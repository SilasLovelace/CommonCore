#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer::Serializer(const Serializer &other) {
    *this = other;
}
Serializer &Serializer::operator=(const Serializer &other) {
    if (this != &other) {}
    return *this;
}
// reinterpret cast jsut treats the bits of the passed parameter as bits of the desired type
// the "regular" C-Style cast eg (int)3.14f is not safe because it is actually a SERIES of casts (including static, const AND reinterpret) trying everything to make the conversion happen
// this makes it unsafer than explicitly using the other types depending on desired conversion
// for example the static cast is checked throwing errors if the conversion is not possible/allowed
uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}
Data *Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}
