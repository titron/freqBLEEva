C����ʵ�� byte תfloat IEEE754
ԭ�� xinyu391 ��󷢲���2017-08-05 10:52:14 �Ķ��� 3711 �ղ�
չ��

���������Ҫ����IEEE754���洢������,������IEEE��׼�Ľ���(�ٶȰٿ�)���������� ��֪����IEEE 754��ʽ��ʲô?)

��C�����ж���float����4�ֽڴ洢��

����

1.618000  �����ڴ���Ϊ 160  26 207    63

1.000000��  ���ڴ���Ϊ  0      0    128    63

��ô����4���ֽ����ݣ�����{160  26 207    63}����ôת��float�أ�

��ʵ�ܼ򵥣�

    float f;
     
    unsigned char *p = (unsinged char*)&f;
     
    p[0]=160;
     
    p[1]=26;
     
    p[2]=207;
     
    p[3]=63;

Ȼ��f������1.618�ˡ�

������Щʱ��û�����ڴ�ֱ�Ӹ�ֵ�����ַ���������glsl�У�

�Ǿ���Ҫ����IEEE754��ת������ת���ˡ�

    #include <math.h>
     
    typedef unsigned char byte;
    float b2f(byte m0, byte m1, byte m2, byte m3)
    {
        // �����λ
        float sig = 1.;
        if (m0 >=128.)
            sig = -1.;
      printf("sig %f\n",sig);
      
    //�����
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
     
    //��β��
     
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
        //float ��λ��ǰ
        byte m0 = pf[3]; //���ֽ�
        byte m1 =pf[2];
        byte m2 = pf[1];
        byte m3 = pf[0];  // ���ֽ�
        f = b2f(m0, m1, m2, m3);
        printf("b2f %f\n", f);
        reutrn 0;
    }
��������������������������������
��Ȩ����������ΪCSDN������xinyu391����ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/xinyu391/java/article/details/76708574