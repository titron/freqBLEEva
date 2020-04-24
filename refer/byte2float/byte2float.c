public class Main {
            //���������floatת����byte[]
             public static byte[] float2byte(float f) {
		
		// ��floatת��Ϊbyte[]
		int fbit = Float.floatToIntBits(f);
		
		byte[] b = new byte[4];  
	    for (int i = 0; i < 4; i++) {  
	        b[i] = (byte) (fbit >> (24 - i * 8));  
	    } 
	    
	    // ��ת����
		int len = b.length;
		// ����һ����Դ����Ԫ��������ͬ������
		byte[] dest = new byte[len];
		// Ϊ�˷�ֹ�޸�Դ���飬��Դ���鿽��һ�ݸ���
		System.arraycopy(b, 0, dest, 0, len);
		byte temp;
		// ��˳λ��i���뵹����i������
		for (int i = 0; i < len / 2; ++i) {
			temp = dest[i];
			dest[i] = dest[len - i - 1];
			dest[len - i - 1] = temp;
		}
	    return dest;
	}
	
	
	
	//���������byteת����float
	public static float byte2float(byte[] b, int index) {  
	    int l;                                           
	    l = b[index + 0];                                
	    l &= 0xff;                                       
	    l |= ((long) b[index + 1] << 8);                 
	    l &= 0xffff;                                     
	    l |= ((long) b[index + 2] << 16);                
	    l &= 0xffffff;                                   
	    l |= ((long) b[index + 3] << 24);                
	    return Float.intBitsToFloat(l);                  
	}
	
	
	
	//���ԣ�������
	public static void main(String[] args) {
		float f = 12.34f;
        byte[] b=float2byte(f);
        for(int i=0;i<3;i++)
        	System.out.println(b[i]);   //���byte���飬��ʾ������ֵ����֣���Ϊfloat���ĸ��ֽڱ���ֳ����ķ�
        float f2=byte2float(b, 0);
        System.out.println(f2);
	}
        
 
}
��������������������������������
��Ȩ����������ΪCSDN������NetRookieX����ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/NetRookieX/java/article/details/80841317