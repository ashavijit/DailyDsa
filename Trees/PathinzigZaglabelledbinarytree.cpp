#include<header.h>
#include<tree.h>

#include <vector>
#include <cmath>

class Solution
{
public:
    std::vector<int> pathInZigZagTree(int label)
    {
        std::vector<int> result;
        int depth = log2(label); // depth of the label using 0 based indexing

        while (depth >= 0)
        {
            result.insert(result.begin(), label); // insert at the beginning of the vector to get the path in the correct order
 
            if (depth == 0)
            {
                break;
            }

            label = (1 << (depth - 1)) + ((1 << depth) - 1) - (label / 2); // label of the parent node
            depth--;
        }

        return result;
    }
};
