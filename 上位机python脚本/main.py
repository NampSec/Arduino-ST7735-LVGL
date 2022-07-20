# 这是一个示例 Python 脚本。

# 按 Shift+F10 执行或将其替换为您的代码。
# 按 双击 Shift 在所有地方搜索类、文件、工具窗口、操作和设置。
import socket
import time

def getgbkoffset(char,width ,hight):
    gbkcode = bytes(char.encode("GB2312")).hex()
    gbkcodeh = int(gbkcode[:2],base=16)
    gbkcodel = int(gbkcode[-2:],base=16)
    if(gbkcodel>=0X40 and gbkcodeh>=0X81):
        if (gbkcodel < 0X7F):
            gbkcodel -= 0X40;
        else:
            gbkcodel -= 0X41;
        return ((gbkcodeh - 0X81) * 190 + (gbkcodel )) * (width * hight / 8)
    else:
        return -1

def openbin(offset):
    if(offset > 0):
        with open("GBK.bin",'rb') as fobj:
            fobj.seek(offset,0)
            data = fobj.read(32)
            return data
    else:
        return bytes(32)


# 按间距中的绿色按钮以运行脚本。
if __name__ == '__main__':
    str = "李剑波你真的是一个好人啊，如果说，连你被人说是坏人的话，那谁是好人呢。  诀绝子的李剑波"
    tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    server_addr = ("192.168.1.87", 1227)
    tcp_socket.connect(server_addr)
    while True:
        k = 0
        while k < len(str):
            #X Y 数据
            #需要offset 为正数，即GBK编码中存在，若不存在返回-1
            offset = int(getgbkoffset(str[k], 16, 16))
            data = int.to_bytes((k % 8) * 16,1,'little') + int.to_bytes(int(k / 8) * 16,1,'little') + openbin(offset)
            tcp_socket.send(data)
            time.sleep(0.5)
            k += 1
        str = input()


    # 5断开
    tcp_socket.close()

# 访问 https://www.jetbrains.com/help/pycharm/ 获取 PyCharm 帮助

