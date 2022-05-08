#pragma once
#include <cstdint>  //including cstdint to allow unassigned integers

typedef std::int16_t hptype; // typedef is used to create a new name using an exsiting data type. this will allow me to use "hptypes" as a data type through out the code.
/*this will also help me if I need to make changes to the hptype from one place.
Using uint16 gives me a max value of 65535 which will be more than enough for the game and will also take up less storage.
Using unassigned int to set the hp as the hp will not go below 0 into the minus, thus making it so its either zero or positive.*/

