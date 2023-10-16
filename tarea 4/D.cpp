#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T> // T es el parámetro de tipo
struct Point{
	T x, y; // ahora x, y son de tipo T
	Point(T _x=0, T _y=0) : x(_x), y(_y) {}
	// Suma y resta
	Point operator+(Point p) const { return Point(x+p.x, y+p.y); }
	Point operator-(Point p) const { return Point(x-p.x, y-p.y); }
	// Multiplicación y división coordenada a coordenada
	Point operator*(Point p) const { return Point(x*p.x, y*p.y); }
	Point operator/(Point p) const { return Point(x/p.x, y/p.y); }
	// Menor e igualdad. Usamos tie que retorna una tupla (y por ende compara en orden de izq. a der.)
	bool operator<(Point p) const { return tie(x,y) < tie(p.x, p.y); }
	bool operator==(Point p) const { return tie(x,y) == tie(p.x, p.y); }
	// De acá en adelante los métodos interpretan al punto como un vector
	// dist2 retorna el largo al cuadrado. Siempre es mejor usarla al cuadrado cuando sea posible para evitar usar doubles
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// dot retorna el producto punto con otro vector.
	T dot(Point p) const { return x*p.x + y*p.y; }
	// cross retorna la tercera coordenada del producto cruz
	T cross(Point p) const { return x*p.y - y*p.x; }
	// unit retorna el vector normalizado (largo 1)
	Point unit() const { return *this/dist(); }
	// perp obtiene un vector perpendicular, es decir rota en +90 grados
	Point perp() const { return Point(-y, x); }
	// normal retorna un vector normal unitario
	Point normal() const { return perp().unit(); }

	// Además se puede hacer overload de operadores ">>" y "<<" para que poder leer/imprimir Point con cin/cout
	friend istream& operator>>(istream& is, Point &p){
		return is >> p.x >> p.y;
	}
	friend ostream& operator<<(ostream& os, const Point &p) {
		return os << "(" << p.x << "," << p.y << ")";
	}
};

/* Retorna -1, 0 o 1 dependiendo del sentido de giro de b a c partiendo de a.
 * Es decir, iniciando en "a" mirando a "b", evalúa el sentido de giro al moverse hasta "c".
 * Otra forma de decirlo es: hacia qué sentido gira el vector bc al ponerlo después del vector ab
 */
template <typename T>
int orientation(Point <T> a, Point <T> b, Point <T> c){
	T v = (b-a).cross(c-b);
	if(v < 0) return -1; // sentido horario
	if(v > 0) return +1; // sentido anti-horario
	return 0; // colineales
}

// Código de Convex Hull. Adaptado de https://cp-algorithms.com/geometry/convex-hull.html#implementation
template <typename T>
vector <Point<T>> convex_hull(vector <Point<T>>& pts){
	// Primero buscamos el punto de menor coordenada p0.
	Point <T> p0 = *min_element(pts.begin(), pts.end());
	// Luego, ordenamos el resto de los puntos según su ángulo con p0.
	sort(pts.begin(), pts.end(), [&p0](const Point<T> &a, const Point<T> &b){
			int o = orientation(p0, a, b);
			if(o == 0){
				return (a-p0).dist() < (b-p0).dist();
			}
			return o > 0;
	});

	// Finalmente, armamos el convex hull.
	vector <Point<T>> hull;
	for(int i=0; i<(int)pts.size(); i++){
		// Descartamos los puntos que hagan un giro en sentido horario.
		while(hull.size() > 1 && orientation(hull[hull.size()-2], hull.back(), pts[i]) <= 0){
			hull.pop_back();
		}
		hull.push_back(pts[i]);
	}
	return hull;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n; cin >> n;//cantidad de vertices
	vector <Point<ll> > pts(n+2);
    Point<ll> sapo;
    Point<ll>sepo;
	for(int i=0; i<n+2; i++){
		cin >> pts[i];
        if(i==n){
            sapo=pts[i];
        }
        if(i==n+1){
            sepo=pts[i];
        }
	}

	vector <Point<ll> > hull = convex_hull(pts);
    int esta1=0,esta2=0;
    int indicesapo, indicesepo;
    for(int i=0; i<hull.size(); i++){
        if(hull[i] == sapo){
            esta1 = 1;
            indicesapo = i;
        }
        else if(hull[i] == sepo){
            esta2 = 1;
            indicesepo=i;
        }
    }
    if(esta1 != esta2){
        cout <<setprecision(8)<<(sapo-sepo).dist() <<endl;
    }
    else{
        int tam =hull.size();
        double camino1 = 0,camino2 = 0;
        for (int i=indicesapo; i!=indicesepo; i = (i+1)%tam) {
        camino1 += (hull[i]-hull[(i+1)%tam]).dist();
        }
        for (int i=indicesepo; i!=indicesapo; i=(i+1)%tam) {
        camino2 += (hull[i]-hull[(i+1)%tam]).dist();
        }
        cout<<setprecision(8)<<min(camino1,camino2)<<endl;
    }
 return 0;
}