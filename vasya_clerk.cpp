/*
The new "Avengers" movie has just been released! There are a lot of people at the cinema box office standing in a huge line. Each of them has a single 100, 50 or 25 dollar bill. An "Avengers" ticket costs 25 dollars.

Vasya is currently working as a clerk. He wants to sell a ticket to every single person in this line.

Can Vasya sell a ticket to every person and give change if he initially has no money and sells the tickets strictly in the order people queue?

Return YES, if Vasya can sell a ticket to every person and give change with the bills he has at hand at that moment. Otherwise return NO.
Examples:

tickets({25, 25, 50}) // => YES 
tickets({25, 100}) // => NO. Vasya will not have enough money to give change to 100 dollars
tickets({25, 25, 50, 50, 100}) // => NO. Vasya will not have the right bills to give 75 dollars of change (you can't make two bills of 25 from one of 50)
*/
#include <string>
#include <vector>

std::string tickets(const std::vector<int>& peopleInLine) {
  /*
    Init Local Variables
  */
  int currentMoney = 0;
  int ticketCost = 25;
  int numHund = 0;
  int numFift = 0;
  int numTwfv = 0;
  int change = 0;
  bool noTest1 = false;
  
  /*
    Loop Through Vector Values
  */
  for (auto i = peopleInLine.begin(); i != peopleInLine.end(); i++) {
    change = (*i - ticketCost); // calculate change
    noTest1 = change > currentMoney; // logic check 1
    
    if (noTest1)
      return "NO";
    
    /*
      Test Giving Change Back With Current Bills
      
      Start From Largest Bill, Work Down To Smallest
      
      If Change Variable Is Not Zero After These Checks,
      Return NO.
    */
    while ((change >= 100) && (numHund > 0)) {
      change -= 100;
      numHund--;
    }
    
    while ((change >= 50) && (numFift > 0)) {
      change -= 50;
      numFift--;
    }
    
    while ((change >= 25) && (numTwfv > 0)) {
      change -= 25;
      numTwfv--;
    }
    
    if (change > 0)
      return "NO";
    
    /*
      Adjust Current Money Value After Calculations
    */
    currentMoney -= (*i - ticketCost);
    currentMoney += *i;
    
    /*
      Update Bill Counts
    */
    if (*i == 25)
      numTwfv++;
    else if (*i == 50)
      numFift++;
    else if (*i == 100)
      numHund++;
    
  }
  
  return "YES";
}
