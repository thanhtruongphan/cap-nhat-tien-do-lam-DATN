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



## **'18/09/24  '**
* Thư viện Gmapping và Catorgrapher
* Nếu bạn đang làm việc với môi trường đơn giản (phẳng) và sử dụng LIDAR 2D, Gmapping là một lựa chọn dễ dàng và hiệu quả.
* Nếu bạn cần lập bản đồ trong không gian 3D hoặc cần độ chính xác cao hơn, Cartographer là một lựa chọn tốt hơn nhưng phức tạp hơn để cài đặt và chạy.
> so sánh phân tích thêm nếu cần

### Sơ lược về SLAM và Gmapping
* 1. Cơ chế hoạt động của SLAM
SLAM (Simultaneous Localization and Mapping) là quá trình robot vừa di chuyển trong môi trường, vừa lập bản đồ, đồng thời định vị chính nó trong bản đồ đó.
Trong Gmapping, thuật toán chủ yếu dựa trên Particle Filter (lọc hạt), nơi mỗi hạt đại diện cho một khả năng vị trí của robot. Dữ liệu từ cảm biến (như LIDAR) sẽ được sử dụng để cập nhật vị trí của các hạt này và tạo ra bản đồ chính xác.
Nghiên cứu sâu về lý thuyết như Bayesian filtering, Monte Carlo Localization (MCL), và Kalman filtering sẽ giúp bạn hiểu rõ cách robot "đoán" vị trí của nó trong không gian.
* 2. Cấu trúc dữ liệu và thuật toán trong Gmapping
Gmapping sử dụng kỹ thuật lọc hạt để duy trì một tập hợp các ước lượng (particles), từ đó dự đoán vị trí của robot. Các Particle Weights được cập nhật liên tục dựa trên sự phù hợp giữa dữ liệu từ cảm biến và bản đồ hiện tại.
Tìm hiểu sâu về cách Scan Matching (khớp dữ liệu quét từ LIDAR) và Odometry (tính toán khoảng cách di chuyển từ cảm biến bánh xe) kết hợp để tối ưu hóa vị trí và tạo bản đồ.
* 3. Quản lý dữ liệu cảm biến
Một phần quan trọng của SLAM là quản lý dữ liệu từ cảm biến như LIDAR, camera, IMU, v.v. Bạn có thể tìm hiểu sâu về cách tích hợp các loại cảm biến này, thu thập và xử lý dữ liệu sao cho phù hợp với thuật toán SLAM.
Bạn cũng cần nghiên cứu về việc xử lý lỗi của cảm biến, độ trễ và khả năng hợp nhất dữ liệu từ nhiều nguồn cảm biến để có được thông tin chính xác hơn.

>>>>>![image](https://github.com/user-attachments/assets/7d3f0f80-04f8-445f-be75-67add3a70dec)
>>>![image](https://github.com/user-attachments/assets/29e8d301-534a-4cc8-b76c-f49a229f0e86)
>>>![image](https://github.com/user-attachments/assets/63738342-bfad-4ad0-b879-6d77060704c2)
>>>![image](https://github.com/user-attachments/assets/602b6cb4-7ac0-4c55-a283-e6c7b27baa4f)
>>>![image](https://github.com/user-attachments/assets/53535e55-f378-4fb0-97b2-191337009cd0)
'''
def a_star(start, goal, grid_map):
    open_list = []
    closed_list = []
    
    start_node = Node(start, None)
    goal_node = Node(goal, None)
    
    open_list.append(start_node)
    
    while open_list:
        current_node = min(open_list, key=lambda node: node.f_cost())
        open_list.remove(current_node)
        closed_list.append(current_node)
        
        if current_node == goal_node:
            return reconstruct_path(current_node)
        
        for neighbor in get_neighbors(current_node, grid_map):
            if neighbor in closed_list or is_obstacle(neighbor, grid_map):
                continue
            
            if neighbor not in open_list:
                open_list.append(neighbor)
            else:
                new_g_cost = current_node.g_cost + move_cost(current_node, neighbor)
                if new_g_cost < neighbor.g_cost:
                    neighbor.g_cost = new_g_cost
                    neighbor.parent = current_node
    
    return None  # Không tìm được đường đi

'''

*Tổng kết:
Xử lý dữ liệu LIDAR để tạo bản đồ lưới là bước đầu tiên quan trọng.
Sau đó, bạn có thể triển khai thuật toán A* để tìm đường tối ưu từ vị trí hiện tại của robot tới đích, trong khi tránh các chướng ngại vật từ dữ liệu LIDAR.

### Dùng ROS hoặc không dùng ROS
* Trong dự án phát triển AMR (Autonomous Mobile Robot), việc sử dụng hoặc không sử dụng ROS (Robot Operating System) phụ thuộc vào độ phức tạp của hệ thống và các chức năng bạn muốn triển khai. Dưới đây là phân tích các phần của hệ thống AMR mà bạn có thể tự làm mà không cần ROS và những phần cần ROS để dễ dàng hơn.

#### Những phần bạn có thể tự làm mà không cần ROS:

**1. Điều khiển cơ bản của robot (Kinematics và động cơ):**

> Bạn có thể tự triển khai các thuật toán điều khiển động cơ, điều hướng và điều khiển tốc độ. Điều này bao gồm việc lập trình trực tiếp các tín hiệu điều khiển cho bánh xe (chẳng hạn qua Arduino hoặc Raspberry Pi).
> Điều khiển kiểu differential drive (xe hai bánh) hoặc mecanum wheels có thể được thực hiện mà không cần ROS.
Quản lý các tín hiệu từ encoder để điều chỉnh tốc độ và vị trí động cơ qua PID control là hoàn toàn có thể tự làm.
**2. Thu thập và xử lý dữ liệu cảm biến:**

    > Nếu chỉ sử dụng các cảm biến cơ bản như LIDAR, camera, hoặc cảm biến siêu âm, bạn có thể lập trình để thu thập dữ liệu từ chúng mà không cần ROS.
    *Ví dụ: Kết nối và đọc dữ liệu từ RPLIDAR, MPU (Inertial Measurement Unit), hoặc camera qua thư viện giao tiếp tương ứng (như thư viện Python cho LIDAR).*

    > Xử lý dữ liệu cảm biến (ví dụ: xây dựng bản đồ lưới từ LIDAR) có thể được thực hiện thủ công bằng cách viết mã xử lý dữ liệu riêng.
**3. Thuật toán định vị và tìm đường:**

    > Nếu bạn muốn tự triển khai các thuật toán định vị (localization) và tìm đường (path planning), như A* hoặc Dijkstra, bạn có thể tự viết các thuật toán này từ đầu.
    > Các hệ thống định vị đơn giản, như sử dụng cảm biến quán tính và encoder, cũng có thể tự làm mà không cần ROS.
**4. Giao tiếp điều khiển từ xa và giao diện người dùng:**

    > Bạn có thể tự thiết kế các giao diện điều khiển (sử dụng Flask cho web interface hoặc giao tiếp qua MQTT) để điều khiển từ xa robot mà không cần ROS.
    > Những tác vụ giao tiếp cơ bản giữa máy tính chủ và robot thông qua mạng hoặc Bluetooth có thể được lập trình mà không cần ROS.
