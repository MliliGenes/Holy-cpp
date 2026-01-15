#include "Serializer.hpp"
#include <iostream>

int main() {
    // Create a Data object
    Data original;
    original.id = 42;
    original.name = "Test Data";
    original.value = 3.14159;
    
    std::cout << "Original Data object:" << std::endl;
    std::cout << "  Address: " << &original << std::endl;
    std::cout << "  ID: " << original.id << std::endl;
    std::cout << "  Name: " << original.name << std::endl;
    std::cout << "  Value: " << original.value << std::endl;
    std::cout << std::endl;
    
    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Serialized value: " << serialized << std::endl;
    std::cout << "  (in hex: 0x" << std::hex << serialized << std::dec << ")" << std::endl;
    std::cout << std::endl;
    
    // Deserialize back to pointer
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized Data object:" << std::endl;
    std::cout << "  Address: " << deserialized << std::endl;
    std::cout << "  ID: " << deserialized->id << std::endl;
    std::cout << "  Name: " << deserialized->name << std::endl;
    std::cout << "  Value: " << deserialized->value << std::endl;
    std::cout << std::endl;
    
    // Verify pointers are equal
    if (deserialized == &original) {
        std::cout << "✓ SUCCESS: Deserialized pointer matches original!" << std::endl;
    } else {
        std::cout << "✗ FAILURE: Pointers do not match!" << std::endl;
    }
    
    // Additional test with dynamic allocation
    std::cout << "\n--- Testing with dynamically allocated Data ---" << std::endl;
    Data* dynamicData = new Data;
    dynamicData->id = 100;
    dynamicData->name = "Dynamic";
    dynamicData->value = 2.71828;
    
    uintptr_t dynamicSerialized = Serializer::serialize(dynamicData);
    Data* dynamicDeserialized = Serializer::deserialize(dynamicSerialized);
    
    std::cout << "Original address: " << dynamicData << std::endl;
    std::cout << "Deserialized address: " << dynamicDeserialized << std::endl;
    
    if (dynamicDeserialized == dynamicData) {
        std::cout << "✓ SUCCESS: Dynamic pointers match!" << std::endl;
        std::cout << "  Data intact: " << dynamicDeserialized->name << std::endl;
    }
    
    delete dynamicData;
    
    return 0;
}