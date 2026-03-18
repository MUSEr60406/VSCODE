#include <iostream>
#include <vector>
#include <string>
using namespace std;

class IntegerSet
{
    private:
        vector<bool> Set;
    public:
        IntegerSet()
        {
            Set.assign(101, false);
        }
        IntegerSet(const vector<int> v, int size)
        {
            Set.assign(101, false);
            for(auto &i : v)
                insertElement(i);
        }
        void insertElement(int element)
        {
            if(element >= 0 && element <= 100)
                Set[element] = true;
        }
        void deleteElement(int element)
        {
            if(element >= 0 && element <= 100)
                Set[element] = false;
        }
        IntegerSet unionOfSets(const IntegerSet &other) const
        {
            IntegerSet I;
            for(int i = 0 ; i <= 100 ; i++)
            {
                if(Set[i] || other.Set[i]) 
                    I.Set[i] = true;
            }
            return I;
        }
        IntegerSet intersectionOfSets(const IntegerSet &other) const
        {
            IntegerSet I;
            for(int i = 0 ; i <= 100 ; i++)
            {
                if(Set[i] && other.Set[i]) 
                    I.Set[i] = true;
            }
            return I;
        }
        bool isEqualTo(const IntegerSet &other) const
        {
            bool equal = true;
            for(int i = 0 ; i <= 100 ; i++)
            {
                if(Set[i] != other.Set[i])
                {
                    equal = false;
                    break;
                }
            }
            return equal;
        }
        void print() const
        {
            bool empty = true;
            for(int i = 0 ; i <= 100 ; i++)
            {
                if(Set[i])
                {
                    cout << i << " ";
                    empty = false;
                }
            }
            if(empty)
                cout << "---";
            cout << "\n";
        }

};

void printLabeledSet(const string& label, const IntegerSet& s)
{
    cout << label;
    s.print();
}
int main()
{
    int n, m;
    cin >> n;

    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    int x, y;
    cin >> x >> y;

    IntegerSet set1(arr1, arr1.size()), set2(arr2, arr2.size());

    printLabeledSet("Set1: ", set1);
    printLabeledSet("Set2: ", set2);

   set1.insertElement(x);
    printLabeledSet("Set1 after insert: ", set1);

    set1.deleteElement(y);
    printLabeledSet("Set1 after delete: ", set1);

    IntegerSet unionSet = set1.unionOfSets(set2);
    IntegerSet intersectionSet = set1.intersectionOfSets(set2);
    printLabeledSet("Union: ", unionSet);
    printLabeledSet("Intersection: ", intersectionSet);

    cout << "Equal: " << (set1.isEqualTo(set2) ? "True" : "False") << endl;

    return 0;
}