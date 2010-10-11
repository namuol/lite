#ifndef _EDGE_H_
#define _EDGE_H_

// Simple tile-edge utility classes/types/enums

namespace lite
{
    enum Edge
    {
        NONE = 0,
        SOLID = 1
    };

    enum EdgeSide
    {
        TOP = 0,
        LEFT = 1,
        BOTTOM = 2,
        RIGHT = 3
    };

    class EdgeArray
    {
        public:
        EdgeArray()
        {
            _edges = {NONE,NONE,NONE,NONE};
        }

        EdgeArray(Edge top, Edge left, Edge bottom, Edge right)
        {
            _edges[TOP] = top;
            _edges[LEFT] = left;
            _edges[BOTTOM] = bottom;
            _edges[RIGHT] = right;
        }

        Edge
        operator[](int index)
        {
            // TODO: Warning msg or error for invalid indices
            return _edges[index % 4]; 
        }

        private:
        Edge _edges[4];
    };
} // namespace lite

#endif
