
#include "TagList.h"

using namespace std;

namespace sdds
{
    void TagList::set()
    {
        tags = nullptr;
        no_of_tags = 0;
        longest_name = 0;
        current = 0;
    }

    void TagList::set(int num)
    {
        cleanup();
        tags = new NameTag[num];
        no_of_tags = num;
        current = 0;
    }

    void TagList::add(const NameTag& nt)
    {
        if (current < no_of_tags)
        {
            tags[current] = nt;
            current++;
            int length = strlen(nt.getName());
            if (length > longest_name)
            {
                longest_name = strlen(nt.getName());
            }
        }
    }

    void TagList::print()
    {
        int i;

        for (i = 0; i < no_of_tags; i++)
        {
            for (int j = 0; j < longest_name + 4; j++)
            {
                cout << "*";
            }
            cout << endl;
            cout << "* " << setw(longest_name) << left << tags[i].getName() << " *" << endl;

            for (int j = 0; j < longest_name + 4; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }

    void TagList::cleanup()
    {
        delete[] tags;
        set();
    }
}