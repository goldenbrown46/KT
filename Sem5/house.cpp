#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cerrno>

std::fstream fileio;

class house
{
public:
  std::string house_name;
  std::string house_address;
  int num_floor;
  int num_door;
  
  house(){};
  house (std::string name, std::string address, int x, int y) {
    house_name = name;
    house_address = address;
    num_floor = x;
    num_door = y;
  }

  void input(const char *filename) {
    std::fstream file;
    file.open(filename, std::ios::app);

    std::string name1 = "House1";
    std::string adr1 = "12_abc_street";
    int nf1 = 4;
    int nd1 = 3;

    this->house_name = name1;
    this->house_address = adr1;
    this->num_floor = nf1;
    this->num_door = nd1;

    //file.write((char*)this, sizeof(house));

    file << this->house_name << ' ' << this->house_address << ' ' << this->num_floor << ' ' << this->num_door;

    file.close();
  }

  void read_file(const char *filename) {
    std::ifstream file;
    std::string text;

    file.open(filename, std::ios::out);

    while(getline(file, text)) {
      std::cout << text;
    }

    file.close();
  }
};

class euro_house: public house
{
public:
  int therm;
  int elec;
  euro_house(
    std::string house_name,
    std::string house_address,
    int num_floor,
    int num_door,
    int therm_eff,
    int elec_eff
  ) : house(
    house_name,
    house_address,
    num_floor,
    num_door
  ){
    therm = therm_eff;
    elec = elec_eff;
  }
};

int main(int argc, char *argv[]) {
  //if (argc != 1) {
    //perror("ERROR");
    //exit(1);
  //}

  house house_test;
  house_test.input(argv[1]);
  house_test.read_file(argv[1]);

  return 0;
}



