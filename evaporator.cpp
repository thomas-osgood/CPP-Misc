/*
    This program tests the life of an evaporator containing a gas.

    We know the content of the evaporator (content in ml), the percentage of foam or gas lost every day (evap_per_day) and the threshold (threshold) in percentage beyond which the evaporator is no longer useful. All numbers are strictly positive.

    The program reports the nth day (as an integer) on which the evaporator will be out of use.

    Note : Content is in fact not necessary in the body of the function "evaporator", you can use it or not use it, as you wish. Some people might prefer to reason with content, some other with percentages only. It's up to you but you must keep it as a parameter because the tests have it as an argument.
*/

using namespace std;
class Evaporator
{
  public:
  static int evaporator(double content, double evap_per_day, double threshold);
};

int Evaporator::evaporator(double content, double evap_per_day, double threshold) {
    // Setup Local Variables
    int returnVal = 0;
    double start_val = content;
    double current_val = content;
    double t_val = content * (threshold / 100.0);
    double amt_lost;
    
    // Calculation Loop
    while (current_val > t_val) {
      // Increment Day Value
      returnVal++; 
      // Calculate Day's Evaporation
      amt_lost = current_val * (evap_per_day / 100.0);
      // Calculate New 'Current Value'
      current_val -= amt_lost;
    }
    
    // Return Day
    return returnVal;
}

