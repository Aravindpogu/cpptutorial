#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Pollen;

const int NCELLS = 20;
const int NBEES  = 10;
const int FSIZE = 11;

const Pollen PATCH_CAPACITY = 9;


template<typename T>
T minimum(T x, T y)
{
  return x < y ? x : y;
}


template<typename T>
T maximum(T x, T y)
{
  return x > y ? x : y;
}


struct Patch
{
  Pollen m_pollen;
  int   m_bees;

  void init();
  void produce();
  void print() const;
};


void Patch::init()
{
  m_pollen = PATCH_CAPACITY;
  m_bees   = 0;
}


void Patch::produce()
{
  if (m_pollen < PATCH_CAPACITY)
  {
    if (rand() % 10 == 0)
      m_pollen++;
  }
}


void Patch::print() const
{
  cout << m_pollen;

  switch (m_bees)
  {
    case 0: cout << ' '; break;
    case 1: cout << '.'; break;
    case 2: cout << ':'; break;
    default: cout << '*'; break;
  }
}


struct Field
{
  Patch m_patch[FSIZE][FSIZE];
  
  void init();  
  void produce();
  void print() const;
};

Field field;

void Field::init()
{
  for (int i = 0; i < FSIZE; i++)
  {
    for (int j = 0; j < FSIZE; j++)
    {
      field.m_patch[i][j].init();
    }
  }
}


void Field::produce()
{
  for (int i = 0; i < FSIZE; i++)
  {
    for (int j = 0; j < FSIZE; j++)
    {
      field.m_patch[i][j].produce();
    }
  }
}


void Field::print() const
{
  for (int i = 0; i < FSIZE; i++)
  {
    for (int j = 0; j < FSIZE; j++)
    {
      field.m_patch[i][j].print();

      cout << ' ';
    }

    cout << endl;
  }
}



enum BeeState { SEARCHING, GATHERING, RETURNING, DEPOSITING };


struct Bee
{
  BeeState m_state;
  int      m_x, m_y;
  Pollen   m_pollen;

  void init(int x, int y);
  void work();
};


Bee  bees[NBEES];


void Bee::init(int x, int y)
{
  m_state = SEARCHING;
  m_x = x;
  m_y = y;
  m_pollen = 0;

  field.m_patch[m_x][m_y].m_bees++;
}


void Bee::work()
{
  switch (m_state)
  {
    case SEARCHING:
    {
      cout << "searching with " << m_pollen << " from (" << m_x << ", " << m_y << ")";

      field.m_patch[m_x][m_y].m_bees--;

      switch (rand() % 4)
      {
        case 0: m_x = maximum(m_x - 1, 0); break;
        case 1: m_y = maximum(m_y - 1, 0); break;
        case 2: m_x = minimum(m_x + 1, FSIZE - 1); break;
        case 3: m_y = minimum(m_y + 1, FSIZE - 1); break;
      }

      Patch& patch = field.m_patch[m_x][m_y];
      
      patch.m_bees++;

      cout << " to (" << m_x << ", " << m_y << ")";

      if (patch.m_pollen > 0)
      {
        m_state = GATHERING;

        cout << ", commencing to gather";
      }

      break;
    }
    case GATHERING:
    {
      Patch& patch = field.m_patch[m_x][m_y];

      cout << "gathering with " << m_pollen << " at (" << m_x << ", " << m_y << ")";

      if (patch.m_pollen > 0)
      {
        m_pollen   += 1;
        patch.m_pollen -= 1;
      }
      else
      {
        m_state = SEARCHING;

        cout << ", recommencing to search";
      }

      break;
    }
    case RETURNING:
    {
      break;
    }
    case DEPOSITING:
    {
      break;
    }
  }

  cout << endl;
}


int main()
{
  field.init();

  for (int i = 0; i < NBEES; i++)
    bees[i].init(FSIZE/2, FSIZE/2);

  while (true)
  {
    field.produce();

    for (int i = 0; i < NBEES; i++)
    {
      bees[i].work();
    }

    field.print();

    cout << endl;

    cin.get();
  }
}

