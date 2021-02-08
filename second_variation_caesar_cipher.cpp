/*
In this country soldiers are poor but they need a certain level of secrecy for their communications so, though they do not know Caesar cypher, they reinvent it in the following way.

They use ASCII, without really knowing it, but code only letters a-z and A-Z. Other characters are kept such as.

They change the "rotate" each new message. This "rotate" is a prefix for their message once the message is coded. The prefix is built of 2 letters, the second one being shifted from the first one by the "rotate", the first one is the first letter, after being downcased, of the uncoded message.

For example if the "rotate" is 2, if the first letter of the uncoded message is 'J' the prefix should be 'jl'.

To lessen risk they cut the coded message and the prefix in five pieces since they have only five runners and each runner has only one piece.

If possible the message will be evenly split between the five runners; if not possible, parts 1, 2, 3, 4 will be longer and part 5 shorter. The fifth part can have length equal to the other ones or shorter. If there are many options of how to split, choose the option where the fifth part has the longest length, provided that the previous conditions are fulfilled. If the last part is the empty string don't put this empty string in the resulting array.

For example, if the coded message has a length of 17 the five parts will have lengths of 4, 4, 4, 4, 1. The parts 1, 2, 3, 4 are evenly split and the last part of length 1 is shorter. If the length is 16 the parts will be of lengths 4, 4, 4, 4, 0. Parts 1, 2, 3, 4 are evenly split and the fifth runner will stay at home since his part is the empty string and is not kept.

Could you ease them in programming their coding?

Example with shift = 1 :

message : "I should have known that you would have a perfect answer for me!!!"

code : => ["ijJ tipvme ibw", "f lopxo uibu z", "pv xpvme ibwf ", "b qfsgfdu botx", "fs gps nf!!!"]

By the way, maybe could you give them a hand to decode?

Caesar cipher : see Wikipedia
 */

class CaesarTwo
{
public:
    static std::vector<std::string> encodeStr(const std::string &s, int shift);
    static std::string decode(std::vector<std::string> &s);

private:
    static char downcase(const char c);
};

using namespace std;

vector<string> CaesarTwo::encodeStr(const string &s, int shift) {
  vector<string> retVal;
  string key, cstr;
  
  int i = 0;
  int l = s.length(), cshift = shift;
  int la = (int)'a', lz = (int)'z', ca = (int)'A', cz = (int)'Z';
  int sc = ((((int)downcase(s[0]) - la) + cshift) % 26) + la;
  
  bool t1 = false, t2 = false;
  int cc;
  
  key.append(1,downcase(s[0]));
  key.append(1,(char)sc);
  cstr += key;
  
  for (i = 0; i < l; i++) {
    cc = (int)s[i];
    t1 = ((cc >= la) && (cc <= lz));
    t2 = ((cc >= ca) && (cc <= cz));
    if (t1) {
      cc = (((cc - la) + cshift) % 26) + la;
    } else if (t2) {
      cc = (((cc - ca) + cshift) % 26) + ca;
    }
    cstr.append(1,(char)cc);
  }
  
  l = cstr.length();
  int overflow = l % 5, div = l / 5;
  int pos = 0, stop = 0;
  string nstr;
  
  if (overflow == 0) {
    for (i = 0; i < 5; i++) {
      stop = pos + div;
      while (pos != stop) {
        nstr.append(1,cstr[pos]);
        pos++;
      }
      retVal.push_back(nstr);
      nstr = "";
    }
  } else {
    for (i = 0; i < 4; i++) {
      stop = pos + div + 1;
      while (pos != stop) {
        nstr.append(1, cstr[pos]);
        pos++;
      }
      retVal.push_back(nstr);
      nstr = "";
    }
    
    for (i = pos; i < l; i++) {
      nstr.append(1,cstr[i]);
    }
    
    if (nstr.length() != 0) {
      retVal.push_back(nstr);
      nstr = "";
    }
  }
  
  return retVal;
}

string CaesarTwo::decode(vector<string> &s) {
  string retVal;
  string key, conci, cstr;
  int la = (int)'a', lz = (int)'z', ca = (int)'A', cz = (int)'Z';
  int pc = 0, cc = 0;
  int vs = s.size(), i = 0;
  
  // Pull Key From Vector
  key.append(1,s[0][0]);
  key.append(1,s[0][1]);
  
  // Determine 'Rotate'
  int rot = (int)key[1] - (int)key[0];
  
  // Condense Vector To String
  for (i = 0; i < vs; i++) {
    conci += s.at(i);
  }
  
  cout << conci << endl;
  int l = conci.length();
  bool t1 = false, t2 = false;
  
  for (i = 2; i < l; i++) {
    cc = (int)conci[i];
    t1 = ((cc >= la) && (cc <= lz));
    t2 = ((cc >= ca) && (cc <= cz));
    
    if (t1) {
      pc = (((cc - la) + (26 - rot)) % 26) + la;
    } else if (t2) {
      pc = (((cc - ca) + (26 - rot)) % 26) + ca;
    } else {
      pc = cc;
    }
    retVal.append(1,(char)pc);
  }
  
  // Return Plaintext
  return retVal;
}

char CaesarTwo::downcase(const char c) {
  char retVal;
  int ic = (int)c;
  int la = (int)'a', ca = (int)'A', cz = (int)'Z';
  bool tst = ((ic >= ca) && (ic <= cz));
  if (tst) {
    retVal = (ic - ca) + la;
  } else {
    retVal = c;
  }
  return retVal;
}
