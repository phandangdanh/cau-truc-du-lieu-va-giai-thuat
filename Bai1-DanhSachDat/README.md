# Ghi chú về danh sách đặt
- Danh sách đặt :
    + Danh sách đặt được tổ chức dưới dạng mảng , kích thước của danh sách đặt là cố định trong suốt quá
    trình hoạt động .
    + Các ô nhớ trong danh sách đặt được tổ chức liên tiếp nhau trong bộ nhớ máy tính .
    + Ưu điểm :
        . Tìm kiếm nhanh chống
    + Nhược điểm :
        .Thao tác thêm sửa xóa sẽ tốn nhiều chi phí và thời gian
- Các chú ý khác :
    + Hàm : khi tạo cần có mục đích của nó là gì và các giá trị tham trị và tham chiếu
        . Nếu bạn muốn lưu lại giá trị của một biến trong hàm sau khi chạy thì dùng tham chiếu vì nó
        sẽ giúp cho bạn lưu trữ giá trị biến đó trong bộ nhớ và có thể sử dụng tiếp tục trong bộ nhớ
        . Nếu bạn muốn không thay đổi tham tri/tham chiếu của hàm thì bạn dùng const ngược lại bạn muốn
        thay đổi thì bạn không dùng const
        . tham trị là bản sao của giá trị (áp dụng thêm const để giữ nguyên giá trị sao chép)
        . tham chiếu là bản gốc của địa chỉ nó ( cần phải thêm dấu & để tham chiếu địa chỉ)
        . Trước hàm phải chú ý kiểu dữ liệu trả về hay không nếu không thì là void và ngược lại có return
    + True và false :
        . Dùng true là false để xác định các trường hợp ngoại khi hàm hoạt động
    + Phải đọc code từ phải sang trái từ là sau dấu "=" và từ trong ra ngoài với các biểu thức