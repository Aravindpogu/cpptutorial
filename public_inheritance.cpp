#include<iostream>
using namespace std;

struct Asset
{
  string m_name;
  double m_cost;
  int    m_purchaseDate;  // year purchased
  double value()
  {
     return m_cost;
  }

  double amortizedCost(int date){
		return m_cost / (date - m_purchaseDate);
   }
};

struct Stock:Asset
{
  string m_symbol;
  int    m_shares;
  double m_lastPrice;

  double value()
  {
     return m_shares * m_lastPrice;
  }
};

struct Bond:Asset
{
  double m_faceValue;
  double m_interestRate;
  int    m_dateOfMaturity;

  double value()
  {
      return m_faceValue * (1.0 + m_interestRate/100
                                  * (m_dateOfMaturity - m_purchaseDate));
   }
};

struct Property:Asset
{
  double m_assessment;

   double value()
   {
            return m_assessment;
    }
};


struct Building:Property
{
  string m_address;
};

struct Art:Property
{
  string m_artist;
  int    m_creationDate;
};

int main()
{
  Stock      microsoft;
  Bond       citicorp;
  Building   beachHouse;
  Art        nighthawks;

  microsoft.m_name         = "Microsoft";
  microsoft.m_symbol       = "MSFT";
  microsoft.m_shares       = 200;
  microsoft.m_lastPrice    = 56;
  microsoft.m_cost         = 8000;
  microsoft.m_purchaseDate = 1994;

  citicorp.m_name           = "Citicorp";
  citicorp.m_faceValue      = 10000;
  citicorp.m_interestRate   = 6.0;
  citicorp.m_dateOfMaturity = 2010;
  citicorp.m_cost           = 9400;
  citicorp.m_purchaseDate   = 1980;

  beachHouse.m_name         = "Beach House";
  beachHouse.m_address      = "123 Seashore Ave, Malibu, CA";
  beachHouse.m_assessment   = 35000;
  beachHouse.m_cost         = 9000;
  beachHouse.m_purchaseDate = 1964;

  nighthawks.m_name         = "Nighthawks";
  nighthawks.m_artist       = "Edward Hopper";
  nighthawks.m_assessment   = 7500;
  nighthawks.m_creationDate = 1942;
  nighthawks.m_cost         = 850;
  nighthawks.m_purchaseDate = 1955;

  cout << "Valuations:\n\n";
  
  cout << "Microsoft stock $" << microsoft .value() << endl;
  cout << "Citicorp bond   $" << citicorp  .value() << endl;
  cout << "Beach house     $" << beachHouse.value() << endl;
  cout << "Nighthawks      $" << nighthawks.value() << endl;

  cout << "Amortized costs per year:\n\n";
  
  cout << "Microsoft stock $" << microsoft .amortizedCost(2002) << endl;
  cout << "Citicorp bond   $" << citicorp  .amortizedCost(2002) << endl;
  cout << "Beach house     $" << beachHouse.amortizedCost(2002) << endl;
  cout << "Nighthawks      $" << nighthawks.amortizedCost(2002) << endl;
}
