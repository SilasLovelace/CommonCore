#include "Serializer.hpp" 

int main(){
    Data *data = new Data();
    std::cout << "Original Data: " << &data << std::endl;
    uintptr_t raw = Serializer::serialize(data);
    std::cout << "Serialized Data: " << raw << std::endl;
    Data *deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data: " << &deserializedData << std::endl;
    delete data;
    return 0;
}