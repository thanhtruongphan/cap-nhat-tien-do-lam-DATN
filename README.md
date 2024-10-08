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

### Những phần cần ROS hoặc dễ dàng hơn khi dùng ROS:
**1. SLAM (Simultaneous Localization and Mapping):** 

* Việc triển khai SLAM (ví dụ như Gmapping, Cartographer) yêu cầu sự tích hợp của nhiều loại cảm biến và dữ liệu thời gian thực. ROS hỗ trợ tốt việc này với các gói có sẵn cho SLAM.
* ROS cung cấp các gói như Gmapping, Cartographer, hoặc RTAB-Map để tạo bản đồ và định vị robot trong thời gian thực. Bạn có thể tự triển khai SLAM mà không cần ROS, nhưng việc quản lý dữ liệu cảm biến và hợp nhất chúng sẽ phức tạp hơn nhiều.
**2. Tích hợp đa cảm biến và đồng bộ hóa:**

* Khi bạn cần tích hợp nhiều loại cảm biến (LIDAR, camera, IMU) và đồng bộ hóa dữ liệu từ các nguồn này, ROS giúp việc này trở nên dễ dàng hơn với các ROS topics và message passing.
* ROS cung cấp các cơ chế để quản lý và đồng bộ hóa dữ liệu từ nhiều nguồn khác nhau trong hệ thống.
**3. Hệ thống điều khiển hành vi (Behavior Trees):**

* Nếu bạn muốn lập trình hành vi phức tạp cho robot, như điều hướng tự động, tránh chướng ngại vật, và đưa ra quyết định trong thời gian thực, ROS giúp bạn dễ dàng thiết lập và quản lý các tiến trình này qua các Node và Action Servers.
* ROS có các gói chuyên dụng để điều khiển hành vi của robot dựa trên các điều kiện môi trường thay đổi.
**4. Visualization (Rviz, rqt):**

* Khi cần giám sát trực quan dữ liệu từ robot như bản đồ, vị trí hiện tại, hoặc thông tin cảm biến, ROS cung cấp công cụ như Rviz và rqt để hiển thị dữ liệu một cách trực quan.
* Nếu không có ROS, bạn sẽ phải tự viết các công cụ hiển thị và giao diện giám sát, điều này mất thời gian và phức tạp hơn.
**6. Tự động điều hướng (Autonomous Navigation):**

* ROS có gói move_base cho điều hướng tự động, giúp bạn xây dựng các lộ trình tránh chướng ngại vật và định vị đích dễ dàng. Nếu không có ROS, bạn sẽ phải tự triển khai thuật toán tránh chướng ngại vật, tính toán lộ trình trong môi trường thay đổi.
**6. Quản lý hệ thống phân tán:**
  
* Nếu bạn muốn triển khai robot AMR với nhiều máy tính, ví dụ Raspberry Pi làm hệ thống nhúng điều khiển và một máy tính khác để xử lý dữ liệu, ROS hỗ trợ tốt việc giao tiếp giữa các máy thông qua ROS Master và ROS Nodes.
* Việc quản lý hệ thống phân tán và giao tiếp giữa các thành phần sẽ phức tạp nếu bạn không sử dụng ROS.
**Kết luận:**
  
* *Phần không cần ROS:* Bạn có thể tự làm điều khiển cơ bản, thu thập và xử lý dữ liệu cảm biến, triển khai các thuật toán tìm đường và định vị đơn giản, giao tiếp điều khiển từ xa mà không cần ROS.
* *Phần cần hoặc dễ dàng hơn khi dùng ROS:* Đối với các chức năng phức tạp như SLAM, điều hướng tự động, đồng bộ hóa đa cảm biến, và visualization, ROS sẽ giúp đơn giản hóa quá trình phát triển và tích hợp hệ thống.

* Nếu bạn muốn đi sâu vào tìm hiểu cơ bản, việc không sử dụng ROS có thể giúp bạn nắm rõ cách hoạt động của từng thành phần. Tuy nhiên, khi dự án phức tạp hơn (đặc biệt là với SLAM và điều hướng), ROS sẽ hỗ trợ rất nhiều.

### Tôi nên sử dụng phiên bản ROS nào cho dự án tốt nghiệp làm xe AMR

* For your university graduation project involving an Autonomous Mobile Robot (AMR), the best version of ROS depends on a few factors like hardware compatibility, desired features, and ease of use. However, here are some guidelines to help you choose the right version:

**1. ROS 1 (Noetic):**

**```Pros:```**
  * The Noetic version is the last long-term support (LTS) release of ROS 1, supported until 2025.
  * It has a large number of packages, including libraries for navigation, SLAM, and sensor integration.
  * Noetic is designed for Ubuntu 20.04, which might be more stable for your project, especially if you have a Raspberry Pi 4 or similar hardware.
  * More documentation and community support are available, which can be helpful for troubleshooting.

**```Cons:```**
  * ROS 1 has a single-threaded architecture and is not as scalable or modern as ROS 2.
**2. ROS 2 (Humble or Foxy):**

**```Pros:```**
  * ROS 2 is the future of the ROS ecosystem, offering better multi-threading, real-time support, and improved communication between nodes.
  * The Foxy version (LTS) and Humble are stable for long-term projects, with support until 2025 and beyond.
  * It has better support for advanced networking and safety-critical applications, which might be useful for an AMR project.
  * If you plan to work on collaborative robots (multi-robot systems) or use DDS (Data Distribution Service) for more robust communication, ROS 2 is highly recommended.

**```Cons:```**
  * The ecosystem is still evolving, and not all ROS 1 packages have been ported to ROS 2.
  * Learning curve: Since ROS 2 has significant changes, you may need to spend extra time learning its new architecture.

'''**Recommendation:**'''
_For your AMR project:_

  * If you need stability and mature packages for SLAM, path planning, and sensor integration (like LIDAR or IMU), ROS 1 Noetic is a safe choice.
  * If you want to future-proof your project or incorporate more advanced real-time features, ROS 2 Humble (or Foxy) is a good option. Since your project involves complex components like LIDAR, MPU, and camera, ROS 2's better real-time processing and multi-threading could be beneficial.

### CÀI ĐẶT ROS-noetic-Ubuntu20.04 Focal fossa
* 
> * Cài đặt môi trường Mô phỏng Linux trên windows (Oracle VM Virtualbox -> Cài Ubuntu 20.04)
> * Cài Ubuntu 20.04 server trên raspberry pi
>
LƯU Ý:
> Raspberry Pi4 có vi xử lý dòng ARMv8, tải theo link: https://cdimage.ubuntu.com/releases/20.04.4/release/
```Khi cài đặt Ubuntu lên thẻ SD```
> https://www.youtube.com/watch?v=Cw_34fuve6E&t=1s&ab_channel=RoboticsBack-End

```Sau khi cài trên thẻ SD xong, cần cấu hình cài đặt mạng trong file _config_network_```
> Password bị mã hóa thành chuỗi số, ta cần phải xóa đi, nhập lại mật khẩu.

> Mở raspberry lên, hệ thống sẽ tự cập nhật dưới nền mất khoảng 1h. Lúc này khi ta dùng lệnh 'sudo apt install...' sẽ hiện thông báo bận như sau: ```Waiting for cache lock: Could not get lock /var/lib/dpkg/lock-frontend. It is held by process 3377 (unattended-upgr) ``` ta cần đợi đến khi nó tự hoàn tất.

* Tiếp theo, cài ROS1 theo link: https://roboticsbackend.com/install-ros-on-raspberry-pi-3/#Install_ROS_on_your_Raspberry_Pi

>>>**Lưu ý:** ![image](https://github.com/user-attachments/assets/6b3a854f-ce6d-4682-ace5-636d937a3475)

**_LƯU Ý:_**
* **Cài Ubuntu 20.04 và ROS noetic trên cả laptop:**
> **Nếu bạn muốn chạy hệ thống phân tán:**
> Cài ROS trên cả laptop và Raspberry Pi: ROS hỗ trợ hệ thống phân tán, nghĩa là bạn có thể chạy các node ROS trên nhiều thiết bị và kết nối chúng với nhau. Ví dụ, bạn có thể chạy các node quản lý, hiển thị trên laptop và các node điều khiển, cảm biến trên Raspberry Pi. Điều này giúp giảm tải cho Pi và tăng khả năng điều khiển robot.


## **'19/09/24  '**
* Cài đặt ROS noetic trên Ubuntu20.04 trên Virtualbox trên laptop theo link: https://www.youtube.com/watch?v=KI6W3iXJLQc&ab_channel=MechDailyLife

```**Lưu ý: **```
> Trường hợp cài trực tiếp theo link hướng dẫn không được thì ```install from source```
> Tuy nhiên sẽ có nhược điểm là mình phải cài mọi thứ thủ công, (tham khảo trên ChatGPT trước tiên)
> Sau này các gói nào thiếu thì cài gói đó, và lưu ý cú pháp cài đặt ```**sudo apt-get install ros-noetic-$<packinstall>**```
> Ex: ```sudo apt-get install ros-noetic-rosbash``` or ```sudo apt-get install ros-noetic-turtlesim```
>
> * Luôn phải source theo mẫu ```echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc``` -> ```source ~/.bashrc```
>
> Lệnh sau có vẻ hữu ích, dù quên mất lỗi gì mà dung:
        >> sudo rosdep init
        >> rosdep update
        >> rosdep install --from-paths /opt/ros/noetic --ignore-src -r -y


**_TÓM LẠI: Làm theo thứ tự trong link:_** https://wiki.ros.org/noetic/Installation/Ubuntu
* _Trường hợp không cài trực tiếp được thì ```install from source```_
* _rồi quay lại tiếp tục các bước 1.5 và 1.6_


### LÀM VIỆC VỚI RPLIDAR
* lỗi
>>>>>>> ![image](https://github.com/user-attachments/assets/12a311e6-016b-42cc-8985-19deada32756)

-> Kiểm tra cổng USB
      ```ls /dev/ttyUSB*```
-> Chỉnh sửa file Launch đúng cổng: 
      ```roscd rplidar_ros/launch```
      ```nano rplidar.launch``` kiểm tra:
      ```<param name="serial_port" value="/dev/ttyUSB0"/>```
-> Kiểm tra quyền truy cập cổng: 
      ```sudo chmod 666 /dev/ttyUSB0```
 
>>> ![image](https://github.com/user-attachments/assets/66873a1a-55b0-4132-ba69-ad902ab6519e)

>>> ![image](https://github.com/user-attachments/assets/dea2a1d0-6c7b-45e0-9d2d-d72384325cc0)

* **lưu ý:** thay rplidar.launch == rplidar_a1.launch _theo đúng tên file trong reposities github_
* nhớ ```cd catkin_ws/src -> git clone https://github.com/Slamtec/rplidar_ros.git``` trên cả Raspberry và Ubuntu trên laptop
* --> cd về ```catkin_ws --> catkin_make --> source ~/.bashrc```

>>> ![image](https://github.com/user-attachments/assets/206e8c13-158e-43d7-920e-bbf4d992cd5c)

>>> ![image](https://github.com/user-attachments/assets/a289fd7a-1536-435f-a02e-c30ee60845da)

>>> ![image](https://github.com/user-attachments/assets/125d1236-af30-487d-a00a-50f195a09f14)

**_Tuy nhiên, cần tạo URDF cho Robot trước, mới đúng quy trình_**

**_Nhận xét thêm: ```hector SLAM``` mình mới phát hiện, thấy ưu việt vãi so với ```Gmapping```, vậy có còn nên sử dụng gmapping không?_**

#### Một vài lỗi khi thực hiện mapping trên Rviz, (hệ thống có Lidar cắm vào Rasp, rasp kết nối Multi-tasking với Laptop qua URI)

> Lệnh xem mô tả cây TF ![image](https://github.com/user-attachments/assets/0f90b1cc-bef4-42a2-9ee3-a58d4c32ad50)

--> Cây có dạng: ![image](https://github.com/user-attachments/assets/af2d3ae9-ae19-4d9a-8471-5c5f7f27163f)

![image](https://github.com/user-attachments/assets/f39d4c5e-8c56-432c-9532-108bd3686227)

* sử dụng lệnh ```ping <IP ADDRESS>``` qua lại để kiểm tra kết nối được chưa
* hoặc sử dụng ```rostopic list```

> Trường hợp mà bị lỗi không xem được [laser] trong Rviz, thì mở thêm **Terminal** chạy lệnh sau:
  ![image](https://github.com/user-attachments/assets/14959ba5-9542-4fb6-b21c-01cbbff6ef5f)
>
>>>>>>>>>>>>>>>>>>>>> ![image](https://github.com/user-attachments/assets/46e96232-47df-4860-bff0-9674b36f3f65)

> Kết quả thực hiện được đến đây như sau:
>>> ![image](https://github.com/user-attachments/assets/2a918589-75dc-4a09-9d45-4be02d054c83)


## **'23/09/24  '**
![image](https://github.com/user-attachments/assets/e2f31a17-98d8-48e7-8044-03b12d5d3ee3)

![image](https://github.com/user-attachments/assets/d4f59be8-33a4-4dcc-a776-921587e80db8)

![image](https://github.com/user-attachments/assets/47575790-aa13-4c8d-9287-c76f4cfc4442)

![image](https://github.com/user-attachments/assets/eb6c1a3d-4ea9-496a-a5a1-955de1ee021d)

## **'24/09/24  '**
![image](https://github.com/user-attachments/assets/e5e6be2b-0ce6-421c-a13b-54aa82da653b)

![image](https://github.com/user-attachments/assets/ed59d235-6146-49df-bc0a-d79fc63e2289)

![image](https://github.com/user-attachments/assets/d7732f80-31f7-40e7-81a2-569dca30dbdf)

--> cd catkin_ws/ --> catkin_make lại sẽ oke.


## **'25/09/24  '**
![image](https://github.com/user-attachments/assets/2057ae82-9cfb-4597-9c58-417d437b138a)

![image](https://github.com/user-attachments/assets/9242458f-4a69-4bfe-8a60-ab946611cf01)
![image](https://github.com/user-attachments/assets/e40dfc64-9329-44be-9476-27c2ff26f395)

