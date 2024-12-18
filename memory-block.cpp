#include <iostream>
#include <bitset>  // استخدام std::bitset لتحويل البايتات إلى تمثيل ثنائي
#include <iomanip> // لاستخدام تنسيق الإخراج

// دالة لطباعة محتويات الذاكرة بالتمثيل الثنائي
void print_bytes(const void* object, size_t size) {
    // تحويل المؤشر إلى نوع `unsigned char*` لقراءة البيانات كـ بايتات
    const unsigned char* bytes = static_cast<const unsigned char*>(object);

    std::cout << "[-";
    for (size_t i = 0; i < size; ++i) {
        std::bitset<8> binary(bytes[i]);  // تحويل البايت إلى تمثيل ثنائي (8 بت)
        std::cout << binary << "-";       // طباعة النتيجة مع فاصل "-"
    }
    std::cout << "]\n\n";
}

// الدالة الرئيسية
int main() {
    std::cout << "\nStoring a Float in Memory";
    std::cout << "\n----------------------------\n\n";

    // تعريف متغير float
    float height = 33.2f;

    // طباعة العنوان، الحجم، والقيمة
    std::cout << "Address is " << static_cast<void*>(&height) << "\n\n";
    std::cout << "Size is " << sizeof(height) << " bytes\n\n";
    std::cout << "Value is " << height << "\n\n";

    // طباعة محتويات الذاكرة بالتفصيل
    std::cout << "Memory Blocks:\n";
    print_bytes(&height, sizeof(height));

    return 0;
}
