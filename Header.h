#ifndef HEADER_H
#define HEADER_H

#include "Matrix.h"
#include "HashDot.h"


Matrix<Vertex*> m;
std::vector<int> connected_bid;
int Matrix<Vertex*>::max_bid = 0;
vector<pair<Vertex*, Direction>> symmetric_corner_inners;
vector<pair<Matrix<Vertex*>::iterator, Direction>> prev_bridge_directions;

bool contains(Vertex* v)
{
    return (m((*v).x, (*v).y)) != nullptr;
}


Direction find(vector<pair<Matrix<Vertex*>::iterator, Direction>> prev_bridge_directions, Matrix<Vertex*>::iterator it)
{
    for (unsigned int i = 0; i < prev_bridge_directions.size(); i++)
        if (prev_bridge_directions[i].first == it)
            return prev_bridge_directions[i].second;
    return None;
}



void connect_2_building(pair<Matrix<Vertex*>::iterator, char>& connectible, int bid)
{
    int i = 0;
   
    pair<Matrix<Vertex*>::iterator, char> connectible_start = connectible;

    if ((**connectible.first).bid != bid)
    {
        int count = 0;
        while (count != 2)
        {
            switch ((*connectible.first)->type)
            {
            case wall:
                (**connectible.first).bid = bid;
                if (connectible.first == connectible_start.first)
                    ++count;
                if (count != 2)
                    connectible.first.move_Clockwise_From_Wall();
                break;
            case corner:
                (**connectible.first).bid = bid;
                connectible.first.move_Clockwise_From_Corner(connectible_start.first, count);
                break;
            case corner_inner:
                (**connectible.first).bid = bid;
                connectible.first.move_Clockwise_From_Corner_Inner();
                break;
            }
        }
    }


    for (unsigned int i = 0; i < symmetric_corner_inners.size(); i++)
        m(symmetric_corner_inners.at(i).first->x, symmetric_corner_inners.at(i).first->y)->prev_direction = symmetric_corner_inners.at(i).second;

    switch (connectible.second)
    {
    case 'R':
        if ((**connectible.first).is_on_bridge_end)
        {
            prev_bridge_directions.push_back(make_pair(connectible.first, (**connectible.first).bridge_direction));
        }
        else
            (**connectible.first).is_on_bridge_end = true;
        (**connectible.first).bid_count++;

        if ((**connectible.first).is_on_bridge_start)
        {
            (**connectible.first).is_on_bridge_start = false;
            prev_bridge_directions.push_back(make_pair(connectible.first, (**connectible.first).bridge_direction));
        }
        (**connectible.first).bridge_direction = Right;
        connectible.first.move_left();
        while (*connectible.first == nullptr || (**connectible.first).is_on_bridge == true)
        {
            auto v = new Vertex(connectible.first.x(), connectible.first.y());
            m(connectible.first.x(), connectible.first.y()) = v;
            (*connectible.first)->is_on_bridge = true;

            m(connectible.first.x(), connectible.first.y())->prev_direction = Right;
            connectible.first.move_left();
        }

       
        if ((**connectible.first).is_on_bridge_start)
        {
            prev_bridge_directions.push_back(make_pair(connectible.first, (**connectible.first).bridge_direction));
        }
        else
            (**connectible.first).is_on_bridge_start = true;
        (**connectible.first).bid_count++;
        if ((**connectible.first).is_on_bridge_end)
        {
            (**connectible.first).is_on_bridge_end = false;

            prev_bridge_directions.push_back(make_pair(connectible.first, (**connectible.first).bridge_direction));
        }
        (**connectible.first).bridge_direction = Right;
        break;
    case 'L':
        if ((**connectible.first).is_on_bridge_end)
        {
            prev_bridge_directions.push_back(make_pair(connectible.first, (**connectible.first).bridge_direction));
        }
        else
            (**connectible.first).is_on_bridge_end = true;
        (**connectible.first).bid_count++;
        if ((**connectible.first).is_on_bridge_start)
        {
            (**connectible.first).is_on_bridge_start = false;
            prev_bridge_directions.push_back(make_pair(connectible.first, (**connectible.first).bridge_direction));
        }
        (**connectible.first).bridge_direction = Left;
        connectible.first.move_right();
        while (*connectible.first == nullptr ||  (**connectible.first).is_on_bridge == true)
        {
            auto v = new Vertex(connectible.first.x(), connectible.first.y());
            m(connectible.first.x(), connectible.first.y()) = v;
            (*connectible.first)->is_on_bridge = true;

            m(connectible.first.x(), connectible.first.y())->prev_direction = Left;
            connectible.first.move_right();
        }
        if ((**connectible.first).is_on_bridge_start)
        {
            prev_bridge_directions.push_back(make_pair(connectible.first, (**connectible.first).bridge_direction));
        }
        else
            (**connectible.first).is_on_bridge_start = true;

        (**connectible.first).bid_count++;
        if ((**connectible.first).is_on_bridge_end)
        {
            (**connectible.first).is_on_bridge_end = false;
            prev_bridge_directions.push_back(make_pair(connectible.first, (**connectible.first).bridge_direction));
        }
        (**connectible.first).bridge_direction = Left;
        break;
    case 'U':
        if ((**connectible.first).is_on_bridge_end)
        {
            prev_bridge_directions.push_back(make_pair(connectible.first, (**connectible.first).bridge_direction));
        }
        else
            (**connectible.first).is_on_bridge_end = true;
        (**connectible.first).bid_count++;
        if ((**connectible.first).is_on_bridge_start)
        {
            (**connectible.first).is_on_bridge_start = false;
            prev_bridge_directions.push_back(make_pair(connectible.first, (**connectible.first).bridge_direction));
        }
        (**connectible.first).bridge_direction = Up;
        connectible.first.move_down();
        while (*connectible.first == nullptr ||  (**connectible.first).is_on_bridge == true)
        {
            auto v = new Vertex(connectible.first.x(), connectible.first.y());
            m(connectible.first.x(), connectible.first.y()) = v;
            (*connectible.first)->is_on_bridge = true;

            m(connectible.first.x(), connectible.first.y())->prev_direction = Up;
            connectible.first.move_down();
        }
        if ((**connectible.first).is_on_bridge_start)
        {
            prev_bridge_directions.push_back(make_pair(connectible.first, (**connectible.first).bridge_direction));
        }
        else
            (**connectible.first).is_on_bridge_start = true;
        (**connectible.first).bid_count++;
        if ((**connectible.first).is_on_bridge_end)
        {
            (**connectible.first).is_on_bridge_end = false;
            prev_bridge_directions.push_back(make_pair(connectible.first, (**connectible.first).bridge_direction));
        }
        (**connectible.first).bridge_direction = Up;
        break;

    case 'D':
        if ((**connectible.first).is_on_bridge_end)
        {
            prev_bridge_directions.push_back(make_pair(connectible.first, (**connectible.first).bridge_direction));
        }
        else
            (**connectible.first).is_on_bridge_end = true;
        (**connectible.first).bid_count++;
        if ((**connectible.first).is_on_bridge_start)
        {
            (**connectible.first).is_on_bridge_start = false;
            prev_bridge_directions.push_back(make_pair(connectible.first, (**connectible.first).bridge_direction));
        }
        (**connectible.first).bridge_direction = Down;
        connectible.first.move_up();
        while (*connectible.first == nullptr || (**connectible.first).is_on_bridge == true)
        {
            auto v = new Vertex(connectible.first.x(), connectible.first.y());
            m(connectible.first.x(), connectible.first.y()) = v;
            (*connectible.first)->is_on_bridge = true;

            m(connectible.first.x(), connectible.first.y())->prev_direction = Down;
            connectible.first.move_up();
        }
        if ((**connectible.first).is_on_bridge_start)
        {
            prev_bridge_directions.push_back(make_pair(connectible.first, (**connectible.first).bridge_direction));
        }
        else
            (**connectible.first).is_on_bridge_start = true;
        (**connectible.first).bid_count++;
        if ((**connectible.first).is_on_bridge_end)
        {
            (**connectible.first).is_on_bridge_end = false;
            prev_bridge_directions.push_back(make_pair(connectible.first, (**connectible.first).bridge_direction));
        }
        (**connectible.first).bridge_direction = Down;
        break;
    }
}

pair<Matrix<Vertex*>::iterator, char> find_Isolated_Building(pair<Matrix<Vertex*>::iterator, char> it, int bid)
{
    auto left_v  = (it.first.left_v (radius));
    auto right_v = (it.first.right_v(radius));
    auto up_v    = (it.first.up_v   (radius));
    auto down_v  = (it.first.down_v (radius));

        if (((**it.first).x + radius < m.rows()) &&
           ((*right_v) != nullptr)               &&
           ((**right_v).bid != (**it.first).bid && (**right_v).bid != 0 && (**right_v).type != inside))
                {
                    it.first.move_right(radius);
                    (it.second) = 'R';
                    return it;
                }

        if ((((**it.first).x - radius) > 0)  &&
           (*left_v != nullptr)              &&
           ((**left_v).bid != (**it.first).bid && (**left_v).bid != 0 && (**left_v).type != inside))
                {
                    it.first.move_left(radius);
                    (it.second) = 'L';
                    return it;
                }
    
        if ((((**it.first).y + radius) < m.cols()) &&
           ((*down_v) != nullptr)                  &&
           ((**down_v).bid != (**it.first).bid && (**down_v).bid != 0 && (**down_v).type != inside))
                {
                    it.first.move_down(radius);
                    (it.second) = 'D';
                    return it;
                }

        if ((((**it.first).y - radius) > 0) && 
           ((*up_v) != nullptr)             &&
           ((**up_v).bid != (**it.first).bid && (**up_v).bid != 0 && (**up_v).type != inside))
                {
                    it.first.move_up(radius);
                    (it.second) = 'U';
                    return it;
                }
    
    return pair<Matrix<Vertex*>::iterator, char>();
}



void find_new_building(Matrix<Vertex*>::iterator& it)
{
    int rows = (**it).x;
    int cols = (**it).y;
    while (cols != m.cols() - 1)
    {
        while (rows != m.rows() - 1)
        {
            if ((*it) != nullptr)
                if (std::find(connected_bid.begin(), connected_bid.end(), (*it)->bid) == connected_bid.end())
                    return;
                else
                {
                    rows++;
                    it.move_right();
                }
            else
            {
                it.move_right();
                rows++;
            }
        }
        it.update(0, ++cols);
        rows = 0;
    }
}

void clean_all()
{
    for (int j = 0; j < m.cols(); j++)
        for (int i = 0; i < m.rows(); i++)
            m(i, j) = nullptr;
   
    symmetric_corner_inners.clear();
    prev_bridge_directions.clear ();
    radius = 0;
    bridge_length           = 0;
    count_of_bridges        = 0;
    non_connected_buildings = 0;
    prev_end                = None;
    prev_start              = None;
    connected_bid.clear();
    m.hash_dot.clear();
    symmetric_corner_inners.clear();
    
}
#endif
