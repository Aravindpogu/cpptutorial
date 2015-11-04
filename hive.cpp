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
  Pollen pollen;
  int    bees;
};


void init(Patch& patch)
{
  patch.pollen = PATCH_CAPACITY;
  patch.bees   = 0;
}


void produce(Patch& patch)
{
  if (patch.pollen < PATCH_CAPACITY)
  {
    if (rand() % 10 == 0)
      patch.pollen++;
  }
}


void print(const Patch& patch)
{
  cout << patch.pollen;

  switch (patch.bees)
  {
    case 0: cout << ' '; break;
    case 1: cout << '.'; break;
    case 2: cout << ':'; break;

    default: cout << '*'; break;
  }
}


struct Field
{
  Patch patch[FSIZE][FSIZE];
};


Field field;


void init(Field& field)
{
  for (int i = 0; i < FSIZE; i++)
  {
    for (int j = 0; j < FSIZE; j++)
    {
      init(field.patch[i][j]);
    }
  }
}


void produce(Field& field)
{
  for (int i = 0; i < FSIZE; i++)
  {
    for (int j = 0; j < FSIZE; j++)
    {
      produce(field.patch[i][j]);
    }
  }
}


void print(const Field& field)
{
  for (int i = 0; i < FSIZE; i++)
  {
    for (int j = 0; j < FSIZE; j++)
    {
      print(field.patch[i][j]);

      cout << ' ';
    }

    cout << endl;
  }
}



enum BeeState { SEARCHING, GATHERING, RETURNING, DEPOSITING };


struct Bee
{
  BeeState state;
  int      x, y;
  Pollen   pollen;
};


Bee  bees[NBEES];


void init(Bee& bee, int x, int y)
{
  bee.state = SEARCHING;
  bee.x = x;
  bee.y = y;
  bee.pollen = 0;

  field.patch[bee.x][bee.y].bees++;
}


void work(Bee& bee)
{
  switch (bee.state)
  {
    case SEARCHING:
    {
      cout << "searching with " << bee.pollen << " from (" << bee.x << ", " << bee.y << ")";

      field.patch[bee.x][bee.y].bees--;

      switch (rand() % 4)
      {
        case 0: bee.x = maximum(bee.x - 1, 0); break;
        case 1: bee.y = maximum(bee.y - 1, 0); break;
        case 2: bee.x = minimum(bee.x + 1, FSIZE - 1); break;
        case 3: bee.y = minimum(bee.y + 1, FSIZE - 1); break;
      }

      Patch& patch = field.patch[bee.x][bee.y];
      
      patch.bees++;

      cout << " to (" << bee.x << ", " << bee.y << ")";

      if (patch.pollen > 0)
      {
        bee.state = GATHERING;

        cout << ", commencing to gather";
      }

      break;
    }
    case GATHERING:
    {
      Patch& patch = field.patch[bee.x][bee.y];

      cout << "gathering with " << bee.pollen << " at (" << bee.x << ", " << bee.y << ")";

      if (patch.pollen > 0)
      {
        bee.pollen   += 1;
        patch.pollen -= 1;
      }
      else
      {
        bee.state = SEARCHING;

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
  init(field);

  for (int i = 0; i < NBEES; i++)
    init(bees[i], FSIZE/2, FSIZE/2);

  while (true)
  {
    produce(field);

    for (int i = 0; i < NBEES; i++)
    {
      work(bees[i]);
    }

    print(field);

    cout << endl;

    cin.get();
  }
}

