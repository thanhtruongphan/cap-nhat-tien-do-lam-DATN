# cap-nhat-tien-do-lam-DATN

## **'13/09/24  '**
>>>>>>>>>>>>> ![image](https://github.com/user-attachments/assets/121c2640-3aab-4533-a9c2-bbdd865246a8)
>>>>>>>>>>>>> ![image](https://github.com/user-attachments/assets/5ce04b4c-7af7-40f3-9a94-cf77d1dae64a)

* Lay hoay cả ngày (thực ra là mấy ngày rồi, sau khi tự phá hỏng 1 con động cơ GA25-370 giá trị khoảng 165k, đổi chiếc mạch L298 mới nữa) thì đã điều khiển được con xe chạy tiến-lùi-trái-phải
* > hướng di chuyển điều khiển bằng phím số 8-2-4-6 == tiến-lùi-trái-phải
  > tốc độ đặt trước
* > Tuy nhiên chưa tùy biến được 'tốc độ đặt'
  > chưa điều khiển chính xác tốc độ với PID (cần thử code PID khác) https://www.youtube.com/watch?v=HRaZLCBFVDE&ab_channel=CurioRes

> [!NOTE] CODE Ở THƯ MỤC 'TEST_DK_VAN_TOC_PID_2BANH_DUNG_KEY02'


## **'16/09/24  '**

* phân loại 1 số H-bridge thông dụng https://www.youtube.com/watch?v=ygrsIqWOh3Y&t=2876s&ab_channel=DroneBotWorkshop
* khắc phục được lỗi nhiễu PID (vì cấp nguồn có áp thấp ko đủ ổn định encoder dẫn đến nhiễu, thay 3,3V bằng 5V là được)
* áp dụng nội dung trong video sau, mọi thứ ổn định như trong video https://www.youtube.com/watch?v=HRaZLCBFVDE&ab_channel=CurioRes
> 'LƯU Ý: ' '''Baud rate''' trong giao tiếp Serial arduino nên chọn phù hợp,
> Baud rate là tốc độ truyền dữ liệu trên cổng nối tiếp (serial communication), được đo bằng số bit truyền trong một giây (bits per second - bps). Trong ngữ cảnh Arduino, baud rate thường được thiết lập khi bạn mở kết nối Serial để giao tiếp giữa Arduino và máy tính hoặc các thiết bị khác.
> Một số giá trị baud rate phổ biến bao gồm:

300
1200
2400
4800
9600 (rất phổ biến)
19200
38400
57600
115200

**Ảnh hưởng của Baud Rate:**
**Tốc độ truyền dữ liệu:**
Baud rate càng cao, tốc độ truyền dữ liệu giữa Arduino và thiết bị khác (như máy tính) càng nhanh. Tuy nhiên, không phải lúc nào baud rate cao hơn cũng tốt hơn, vì nó còn phụ thuộc vào khả năng của cả Arduino và thiết bị nhận.
9600 baud là tốc độ truyền thông thường dùng, nhưng nếu bạn cần truyền dữ liệu nhanh hơn, bạn có thể chọn các giá trị cao hơn như 115200 baud.
**Khả năng lỗi trong giao tiếp:**

Baud rate quá cao có thể gây ra lỗi trong quá trình truyền dữ liệu nếu phần cứng không theo kịp, dẫn đến mất dữ liệu, đặc biệt nếu dây nối quá dài hoặc điều kiện môi trường không tốt.
Baud rate quá thấp sẽ làm giảm tốc độ truyền dữ liệu và có thể khiến chương trình hoạt động chậm hơn mức cần thiết, gây ra hiệu suất không như mong muốn.
Độ tin cậy và sự ổn định:

Baud rate thấp có thể tăng độ tin cậy vì tốc độ truyền chậm hơn sẽ giảm khả năng mất mát hoặc sai sót dữ liệu. Tuy nhiên, điều này có thể làm giảm hiệu suất của hệ thống, đặc biệt khi truyền lượng dữ liệu lớn.
Baud rate cao có thể đạt được tốc độ truyền cao hơn nhưng dễ gặp vấn đề về mất dữ liệu hoặc nhiễu tín hiệu, đặc biệt trên các mạch hoặc dây dẫn dài.
**Tương thích giữa thiết bị:**

Baud rate của Arduino và thiết bị giao tiếp (như máy tính, module Bluetooth, module GSM, hoặc các vi điều khiển khác) phải giống nhau để truyền thông thành công. Nếu baud rate không khớp, dữ liệu sẽ bị sai lệch hoặc không thể truyền được.
Khả năng xử lý của Arduino:

Nếu baud rate quá cao, Arduino có thể gặp khó khăn trong việc xử lý và trả lời dữ liệu kịp thời, đặc biệt là khi bạn đang thực hiện các tác vụ khác như điều khiển động cơ, đọc cảm biến,...
Khi nào nên sử dụng baud rate cao hoặc thấp?
Baud rate thấp: Phù hợp khi bạn cần truyền dữ liệu ít và cần đảm bảo tính ổn định và độ tin cậy, hoặc khi giao tiếp qua các đường truyền dài, môi trường nhiễu, hoặc tốc độ xử lý của thiết bị giới hạn.

Baud rate cao: Thích hợp khi cần truyền dữ liệu nhanh với khối lượng lớn hoặc khi cần truyền các dữ liệu thời gian thực như video hoặc tín hiệu cảm biến tốc độ cao.

### Tune PID
**Kp = 3.2**
>>>>>>>>>>>> ![image](https://github.com/user-attachments/assets/fe205b84-03ce-4681-8c66-8600bbe9a6f9)

**Kp = 3.2, Ki = 1**
**Kp = 1.5, Ki = 1.6**
>>>>>>>>>>>> ![image](https://github.com/user-attachments/assets/c8300054-6f7e-4816-951e-e38ec695e1d4)

**Kp = 0.5, Ki = 0.95, code tính PID phương pháp 2 link YT: https://www.youtube.com/watch?v=HRaZLCBFVDE&ab_channel=CurioRes**
> đường màu vàng đáp ứng số 1, màu đen là đáp ứng số 2
> 
![image](https://github.com/user-attachments/assets/7e08b4fa-4a26-419d-8bc5-5b7ba0ed78d8)

![image](https://github.com/user-attachments/assets/9111e4db-88c8-4edc-948e-d7b837e46ab6)

![image](https://github.com/user-attachments/assets/eff01b99-e9f8-4d10-bfac-b43c68a09d39)

> [!NOTE] CODE Ở THƯ MỤC "PID_servo_control_with_fillter_2BANH_02"

* Đã điều khiển được trên Raspberry qua giao thức 'serial'
![image](https://github.com/user-attachments/assets/cee8b13c-feeb-4c14-9280-4156b09a6531)

