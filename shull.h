#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <unordered_set>
#include <unordered_map>

#define SHFLT double
#define PSHFLT "f"

class sh_triangle;

class sh_point {
public:
    SHFLT x;
    SHFLT y;
    float value;
    int idx;
    std::unordered_set<int> neighbors; // index of neighbor point in points array
    double grad[2];
};

class sh_edge {
public:
    sh_point *p[2];
    sh_triangle *t[2];
    unsigned int flipcount;
};

class sh_triangle {
public:
    sh_point *p[3];
    sh_edge *e[3];
    sh_point cc;
    SHFLT ccr2;
};

typedef struct {
    ll_node *hull_edges;
    ll_node *internal_edges;
    ll_node *triangles;
    double minX = 180;
    double minY = 90;
    double maxX = -180;
    double maxY = -90;
    sh_point *pts;
} sh_triangulation_data;

int triangulate(sh_triangulation_data *td, sh_point *ps, size_t n);
int make_delaunay(sh_triangulation_data *td);
int delaunay(sh_triangulation_data *td, sh_point *ps, size_t n);
