#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
 
using namespace std;
 
typedef int Pollen;
 
const int NCELLS = 20;
const int NBEES  = 10;
const int FSIZE = 11;
 
const Pollen PATCH_CAPACITY = 9;
 
struct Patch
{
    Pollen pollen;
    int    bees;
 
    Patch()
    {
        pollen = PATCH_CAPACITY;
        bees   = 0;
    }
    
    
    void produce()
    {
        if (pollen < PATCH_CAPACITY)
        {
            if (rand() % 10 == 0)
                pollen++;
        }
    }
    
    void print() const
    {
        cout << pollen;
        
        switch (bees)
        {
            case 0: cout << ' '; break;
            case 1: cout << '.'; break;
            case 2: cout << ':'; break;
                
            default: cout << '*'; break;
        }
    }
};
 
struct Field
{
    Patch patch[FSIZE][FSIZE];
 
    Field() {}
    
    void produce()
    {
        for (int i = 0; i < FSIZE; i++)
        {
            for (int j = 0; j < FSIZE; j++)
            {
                patch[i][j].produce();
            }
        }
    }
 
    void print() const
    {
        for (int i = 0; i < FSIZE; i++)
        {
            for (int j = 0; j < FSIZE; j++)
            {
                patch[i][j].print();
                
                cout << ' ';
            }
            
            cout << endl;
        }
    }
};
 
Field field;
 
// Replace with a type safe enum the size of an unsigned short
enum class BeeState { SEARCHING, GATHERING, RETURNING, DEPOSITING };
 
class Bee
{
    BeeState state;
    int      x, y;
    Pollen   pollen;
public:
    Bee() : state(BeeState::SEARCHING), x(0), y(0), pollen(0)
    {
    }
    
    // Delegate to the default constructor
    // only provide the added functionality
    // i.e. setting values for x, y and the patch

    // Tried to use constructor delegation. But, it seems my compiler does not support this feature.
    Bee(int x, int y)//: Bee()
    {
        state = BeeState::SEARCHING;
	this->x = x;
        this->y = y;
	pollen = 0;        

        field.patch[x][y].bees++;
    }
    
    void work()
    {
        switch (state)
        {
            case BeeState::SEARCHING:
            {
                cout << "searching with " << pollen << " from (" << x << ", " << y << ")";
                
                field.patch[x][y].bees--;
                
                switch (rand() % 4)
                {
                    case 0: x = max(x - 1, 0); break;
                    case 1: y = max(y - 1, 0); break;
                    case 2: x = min(x + 1, FSIZE - 1); break;
                    case 3: y = min(y + 1, FSIZE - 1); break;
                }
                
                Patch& patch = field.patch[x][y];
                
                patch.bees++;
                
                cout << " to (" << x << ", " << y << ")";
                
                if (patch.pollen > 0)
                {
                    state = BeeState::GATHERING;
                    
                    cout << ", commencing to gather";
                }
                
                break;
            }
            case BeeState::GATHERING:
            {
                Patch& patch = field.patch[x][y];
                
                cout << "gathering with " << pollen << " at (" << x << ", " << y << ")";
                
                if (patch.pollen > 0)
                {
                    pollen   += 1;
                    patch.pollen -= 1;
                }
                else
                {
                    state = BeeState::SEARCHING;
                    
                    cout << ", recommencing to search";
                }
                
                break;
            }
            case BeeState::RETURNING:
            {
                break;
            }
            case BeeState::DEPOSITING:
            {
                break;
            }
        }
        
        cout << endl;
    }
};
 
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    
    // Replace with initialization list (pick random locations for the bees)
    // e.g. vector<Bee> bees { {5, 8}, {9, 1} ... };
    vector<Bee> bees;
    for (int i = 0; i < NBEES; i++) {
        bees.push_back(Bee(FSIZE/2, FSIZE/2));
    }
    
    while (true)
    {
        field.produce();
        
        // Replace with range-based for
        //for (vector<Bee>::iterator bee = bees.begin(); bee != bees.end(); ++bee)
        for (auto& bee : bees)
        {
            bee.work();
        }
        
        field.print();
        
        cout << endl;
        
        cin.get();
    }
}
