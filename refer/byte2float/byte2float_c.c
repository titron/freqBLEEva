C语言实现 byte 转float IEEE754
原创 xinyu391 最后发布于2017-08-05 10:52:14 阅读数 3711 收藏
展开

编程语言主要采用IEEE754来存储浮点数,这里有IEEE标准的介绍(百度百科)，或者这里 （知乎：IEEE 754格式是什么?)

在C语言中对于float，用4字节存储，

比如

1.618000  ，在内存中为 160  26 207    63

1.000000，  在内存中为  0      0    128    63

那么我有4个字节数据，比如{160  26 207    63}，怎么转成float呢？

其实很简单：

    float f;
     
    unsigned char *p = (unsinged char*)&f;
     
    p[0]=160;
     
    p[1]=26;
     
    p[2]=207;
     
    p[3]=63;

然后f，就是1.618了。

但是有些时候，没有用内存直接赋值的这种方法，比如glsl中，

那就需要根据IEEE754标转来进行转换了。

    #include <math.h>
     
    typedef unsigned char byte;
    float b2f(byte m0, byte m1, byte m2, byte m3)
    {
        // 求符号位
        float sig = 1.;
        if (m0 >=128.)
            sig = -1.;
      printf("sig %f\n",sig);
      
    //求阶码
        float jie = 0.;
         if (m0 >=128.)
        {
            jie = m0-128.  ;
        }
        else
        {
            jie = m0;
        }
        jie = jie * 2.;
        if (m1 >=128.)
            jie += 1.;
        printf("jie %f\n",jie);
        jie -= 127.;
    printf("jie %f\n",jie);
     
    //求尾码
     
        float tail = 0.;
        if (m1 >=128.)
            m1 -= 128.;
        tail =  m3 + (m2 + m1 * 256.) * 256.;
        printf("tail %f\n",tail);
        tail  = (tail)/8388608;   //   8388608 = 2^23
        printf("tail %f\n",tail);
     
        float f = sig * pow(2., jie) * (1+tail);
     
        return f;
    }
     
    int main(int argc, char *argv[])
    {
        float f = 1;
        byte *pf = (byte *)&f;
        printf("F: %f  %d %d %d %d \n", f, pf[0], pf[1], pf[2], pf[3]);
        //float 低位在前
        byte m0 = pf[3]; //高字节
        byte m1 =pf[2];
        byte m2 = pf[1];
        byte m3 = pf[0];  // 低字节
        f = b2f(m0, m1, m2, m3);
        printf("b2f %f\n", f);
        reutrn 0;
    }
————————————————
版权声明：本文为CSDN博主「xinyu391」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/xinyu391/java/article/details/76708574