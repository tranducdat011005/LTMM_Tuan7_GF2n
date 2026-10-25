# Bài tập tuần 7 - Lý thuyết mật mã

Họ và tên: Trần Đức Đạt
MSSV: 20233311

## Nội dung
Cài đặt thuật toán nhân hai đa thức trong trường hữu hạn GF(2^4) và GF(2^8) bằng ngôn ngữ C.

## Thuật toán
Sử dụng thuật toán "Russian Peasant Multiplication" (Nhân nông dân Nga) trên bit:
- Duyệt từng bit của toán hạng thứ 2.
- Nếu bit là 1, XOR kết quả với toán hạng thứ nhất.
- Dịch trái toán hạng thứ nhất. Nếu tràn bit (vượt quá bậc của trường), XOR với đa thức tối giản để giảm bậc.

## Cách biên dịch và chạy
```bash
gcc gf_multiply.c -o gf_multiply
./gf_multiply