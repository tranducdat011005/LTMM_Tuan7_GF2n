#include <stdio.h>
#include <stdint.h>

/**
 * Hàm nhân hai đa thức trong trường hữu hạn GF(2^n)
 * 
 * @param a       Đa thức thứ nhất (biểu diễn dạng số nguyên)
 * @param b       Đa thức thứ hai (biểu diễn dạng số nguyên)
 * @param modulus Đa thức tối giản (dạng số nguyên)
 * @param n_bits  Số bit của trường (VD: 4 cho GF(2^4), 8 cho GF(2^8))
 * @return        Kết quả phép nhân dưới dạng số nguyên
 */
uint16_t gf_multiply(uint16_t a, uint16_t b, uint16_t modulus, int n_bits) {
    uint16_t result = 0;
    // Mặt nạ để kiểm tra bit cao nhất (MSB - Most Significant Bit)
    uint16_t msb_mask = 1 << (n_bits - 1);

    for (int i = 0; i < n_bits; i++) {
        // Nếu bit thấp nhất của b là 1, cộng (XOR) a vào kết quả
        if (b & 1) {
            result ^= a;
        }

        // Dịch phải b để xét bit tiếp theo
        b >>= 1;

        // Lưu lại bit cao nhất của a trước khi dịch
        uint16_t carry = a & msb_mask;

        // Dịch trái a
        a <<= 1;

        // Nếu a bị tràn bit (bit cao nhất là 1), thực hiện giảm bậc modulo
        if (carry) {
            a ^= modulus;
        }
    }

    return result;
}

int main() {
    // ==========================================
    // KIỂM THỬ TRONG GF(2^4)
    // ==========================================
    printf("--- KIEM THU TRONG GF(2^4) ---\n");
    // Đa thức tối giản: x^4 + x + 1 -> Nhị phân: 10011 -> Hex: 0x13
    uint16_t mod_4 = 0x13; 
    int n_bits_4 = 4;

    // Ví dụ: Nhân (x^2 + 1) và (x^3 + x)
    // a = 0101 (0x5), b = 1010 (0xA)
    uint16_t a4 = 0x05;
    uint16_t b4 = 0x0A;
    uint16_t res4 = gf_multiply(a4, b4, mod_4, n_bits_4);
    
    printf("Nhan %X va %X trong GF(2^4) = %X\n", a4, b4, res4);
    printf("(Ky vong: 4)\n\n");

    // ==========================================
    // KIỂM THỬ TRONG GF(2^8)
    // ==========================================
    printf("--- KIEM THU TRONG GF(2^8) ---\n");
    // Đa thức tối giản: x^8 + x^4 + x^3 + x + 1 (Chuẩn AES) -> Hex: 0x11B
    uint16_t mod_8 = 0x11B;
    int n_bits_8 = 8;

    // Test case kinh điển trong chuẩn AES: 0x57 * 0x83
    uint16_t a8 = 0x57;
    uint16_t b8 = 0x83;
    uint16_t res8 = gf_multiply(a8, b8, mod_8, n_bits_8);
    
    printf("Nhan %X va %X trong GF(2^8) = %X\n", a8, b8, res8);
    printf("(Ky vong: C1)\n");

    return 0;
}