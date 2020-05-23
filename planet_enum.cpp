std::string get_planet_name(int id)
{
  enum planets {Mercury = 1, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptune};
  std::string retVal;
  
  switch (planets(id)) {
      case Mercury:
          retVal = "Mercury";
          break;
      case Venus:
          retVal = "Venus";
          break;
      case Earth:
          retVal = "Earth";
          break;
      case Mars:
          retVal = "Mars";
          break;
      case Jupiter:
          retVal = "Jupiter";
          break;
      case Saturn:
          retVal = "Saturn";
          break;
      case Uranus:
          retVal = "Uranus";
          break;
      case Neptune:
          retVal = "Neptune";
          break;
      default:
          retVal = "INVALID";
          break;
  }
  
  return retVal;
}

