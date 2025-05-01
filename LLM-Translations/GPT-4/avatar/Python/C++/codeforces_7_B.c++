
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int t, m;
    std::cin >> t >> m;
    std::vector<int> alocuente(m, 0);
    int ind = 1;
    for (int i = 0; i < t; i++)
    {
        std::string op;
        std::cin >> op;
        if (op == "alloc")
        {
            int pos = 0;
            int size;
            std::cin >> size;
            for (int j = 0; j < m; j++)
            {
                if (alocuente[j] == 0)
                {
                    pos++;
                    if (pos == size)
                    {
                        std::fill(alocuente.begin() + j - size + 1, alocuente.begin() + j + 1, ind);
                        std::cout << ind << std::endl;
                        ind++;
                        break;
                    }
                }
                else
                {
                    pos = 0;
                }
            }
            if (pos != size)
            {
                std::cout << "NULL" << std::endl;
            }
        }
        else if (op == "erase")
        {
            int num;
            std::cin >> num;
            if (std::count(alocuente.begin(), alocuente.end(), num) == 0 || num == 0)
            {
                std::cout << "ILLEGAL_ERASE_ARGUMENT" << std::endl;
            }
            else
            {
                std::replace(alocuente.begin(), alocuente.end(), num, 0);
            }
        }
        else if (op == "defragment")
        {
            alocuente.erase(std::remove(alocuente.begin(), alocuente.end(), 0), alocuente.end());
            while (alocuente.size() < m)
            {
                alocuente.push_back(0);
            }
        }
    }
    return 0;
} // End of Code

This C++ code behaves in the same manner as the provided Python code. It reads the number of operations and the size of the array. Then, it reads each operation and performs the corresponding action. If the operation is 'alloc', it tries to find a contiguous block of unallocated space in the array. If the operation is 'erase', it tries to erase a previously allocated block. If the operation is 'defragment', it moves all the unallocated space to the end of the array.
