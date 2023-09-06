const int V = 100, E = 1000;
struct Edge {int a, b, c;} e[E];	// edge list
bool operator<(Edge e1, Edge e2) {return e1.c < e2.c;}

int p[V];
void init() {for (int i=0; i<V; ++i) p[i] = i;}
int find(int x) {return x == p[x] ? x : (p[x] = find(p[x]));}
void merge(int x, int y) {p[find(x)] = find(y);}

void Kruskal(){
	init();
	sort(e, e+E);
	int i, j;
	for (i = 0, j = 0; i < V-1 && j < E; ++i){
		while (find(e[j].a) == find(e[j].b)) j++;
		merge(e[j].a, e[j].b);
		cout << "起點：" << e[j].a<< "終點：" << e[j].b<< "權重：" << e[j].c;
		j++;	
	}
	if (i == V-1) cout << "得到最小生成樹";
	else          cout << "得到最小生成森林";
}