public class Main {
            //这个函数将float转换成byte[]
             public static byte[] float2byte(float f) {
		
		// 把float转换为byte[]
		int fbit = Float.floatToIntBits(f);
		
		byte[] b = new byte[4];  
	    for (int i = 0; i < 4; i++) {  
	        b[i] = (byte) (fbit >> (24 - i * 8));  
	    } 
	    
	    // 翻转数组
		int len = b.length;
		// 建立一个与源数组元素类型相同的数组
		byte[] dest = new byte[len];
		// 为了防止修改源数组，将源数组拷贝一份副本
		System.arraycopy(b, 0, dest, 0, len);
		byte temp;
		// 将顺位第i个与倒数第i个交换
		for (int i = 0; i < len / 2; ++i) {
			temp = dest[i];
			dest[i] = dest[len - i - 1];
			dest[len - i - 1] = temp;
		}
	    return dest;
	}
	
	
	
	//这个函数将byte转换成float
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
	
	
	
	//测试，主函数
	public static void main(String[] args) {
		float f = 12.34f;
        byte[] b=float2byte(f);
        for(int i=0;i<3;i++)
        	System.out.println(b[i]);   //输出byte数组，显示的是奇怪的数字，因为float的四个字节被拆分成了四份
        float f2=byte2float(b, 0);
        System.out.println(f2);
	}
        
 
}
————————————————
版权声明：本文为CSDN博主「NetRookieX」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/NetRookieX/java/article/details/80841317