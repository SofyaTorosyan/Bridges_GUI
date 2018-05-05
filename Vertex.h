#ifndef VERTEX_H
#define VERTEX_H
struct Point
{
    int x;
    int y;
};

enum Type
{
    corner,
    corner_inner,
    wall,
    inside
};

enum Direction
{
    Up,
    Down,
    Left,
    Right,
    None
};

struct Vertex : Point
{
    Vertex(int a, int b)
    {
        x = a;
        y = b;
        bid = 0;
        bridge_end = 0;
        bridge_start = 0;
        bid_count = 0;
        count_for_corner_inners = 0;
        is_on_bridge = false;
        is_on_bridge_end = false;
        is_on_bridge_start = false;
        type = Type::corner;
        prev_direction = None;
        bridge_direction = None;
    }

    Vertex() {
        bid = 0;
        bridge_end = 0;
        bridge_start = 0;
        bid_count = 0;
        count_for_corner_inners = 0;
        is_on_bridge = false;
        is_on_bridge_end = false;
        is_on_bridge_start = false;
        type = Type::corner;
        prev_direction = None;
        bridge_direction = None;
    }
    int bid;
    int bridge_end;
    int bridge_start;
    int bid_count;
    int  count_for_corner_inners;
    bool is_on_bridge;
    bool is_on_bridge_end;
    bool is_on_bridge_start;
    Type type;
    Direction prev_direction;
    Direction bridge_direction;
};
namespace
{
    int radius = 0;
    Direction prev_end = None;
    Direction prev_start = None;
    int count_of_bridges = 0;
    int bridge_length = 0;
    int non_connected_buildings = 0;
}

#endif
