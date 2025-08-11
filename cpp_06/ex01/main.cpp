#include "Serializer.hpp"

int main()
{
    Data myData;
    myData.id = 42;
    myData.name = "Umut";
    myData.value = 3.14;

    std::cout << "Original Data:" << std::endl;
    std::cout << "  id: " << myData.id << std::endl;
    std::cout << "  name: " << myData.name << std::endl;
    std::cout << "  value: " << myData.value << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "\nSerialized pointer (uintptr_t): " << raw << std::endl;

    Data* restored = Serializer::deserialize(raw);

    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "  id: " << restored->id << std::endl;
    std::cout << "  name: " << restored->name << std::endl;
    std::cout << "  value: " << restored->value << std::endl;

    if (restored == &myData)
        std::cout << "\n[OK] Pointer restore successful!" << std::endl;
    else
        std::cout << "\n[ERROR] Pointer restore failed!" << std::endl;

    return (0);
}
