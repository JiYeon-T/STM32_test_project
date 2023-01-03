������:

(1)��ջ����������, ������ RAM �� ��û�п����� flash �� Ӧ�ò��ᣬ flash �൱�ڴ��̣�
(2)����������һ��cmsis.h, cmsis.c �ṩ�ӿ�, �� FreeRTOS �Ľӿڽ��з�װ, �����л�����ϵͳʱ��ֻ��Ҫ�޸�����ļ�����, ��ǿ����Ŀ���ֲ��;

**�ú�ѧѧ"��־ΰ"д�Ĵ��룬alarm Ҳ��ʹ��������й���ģ�db_alarm_clock.c**

���ֲ���Ҳ��ʹ��������й���

(5) �� GUI ���й���ÿһ��С�������һ���̣߳���ʾÿ���߳��յ���Ϣ������Լ��߳��йص���Ϣ��

| name           | info            |
| -------------- | --------------- |
| Thread manager | msg:16 info:abc |
| Thread monitor | msg:17 info:def |
| Thread key     | msg:5 info:ddd  |
| Thread LED     | msg:8 info:www  |
| Thread ...     | msg:1 info:zzz  |



##### FreeRTOS

##### 1.Task

```C
BaseType_t xTaskCreate( TaskFunction_t pxTaskCode,
                        const char * const pcName,
                        const uint16_t usStackDepth,
                        void * const pvParameters,
                        UBaseType_t uxPriority,
                        TaskHandle_t * const pxCreatedTask );
```

?	������Ҫ RAM �������������йص�״̬��Ϣ(������ƿ�)������Ҳ��Ҫһ���� RAM ����Ϊ�����ջ�����ʹ�ú��� xTaskCreate()����������Ļ�����ô��Щ**����� RAM �ͻ��Զ��Ĵ� FreeRTOS �Ķ��з���**��**��˱����ṩ�ڴ�����ļ���Ĭ������ʹ��heap_4.c ����ڴ�����ļ������Һ� configSUPPORT_DYNAMIC_ALLOCATION ����Ϊ 1**�����ʹ�ú��� xTaskCreateStatic()�����Ļ���Щ RAM ����Ҫ�û����ṩ�ˡ�

?	�´���������Ĭ�Ͼ��Ǿ���̬�ģ������ǰû�б����������ȼ�������������ô������ͻ�������������̬��ʼ���У��������������������ǰ���������󣬶����Դ�������

###### 1.1 ����

�����������������������ж�֮�䴫�����ݣ������ݿ����������У���������ȡ����Ч�ʱȽϵ�;

UCOS ����ϵͳ�ʹ������ݵ����ã�ָ�룩�����Ǳ���Ҫ��֤���ݴ���;

**ֱ��������������ݵ�ָ��Ҳ����ʵ�ִ����������õ�Ŀ�ģ�ͬ���ģ�Ҫ��֤���ݴ��ڣ���������Ҫ���͵���Ϣ����̫���ʱ��Ϳ���ֱ�ӷ�����Ϣ�������ĵ�ַָ�룬**

eg:

����������Ӧ�û����У�������������������ܴ�ģ��������ݿ����Ļ��Ͳ���ʵ��

��������:

```C
QueueHandle_t xQueueCreate(UBaseType_t uxQueueLength, UBaseType_t uxItemSize);
```

�˺�����������һ���꣬������̬�������У��˺����յ��õ��Ǻ��� xQueueGenericCreate()��

###### 1.2 �ź���

�ź����������ڿ��ƶԹ�����Դ�ķ��ʣ�Ҳ���������߳�ͬ��;

��ֵ�ź���:�������������� �Լ� �������ж�֮���ͬ��;

�������ź���

�����ź���

##### ����:�������ͷ��ź������������´���

**��û�н��**

����:Error:..\..\FreeRTOS\portable\RVDS\ARM_CM3\port.c,714

![image-20220116202846592](C:\Users\qz\AppData\Roaming\Typora\typora-user-images\image-20220116202846592.png)



##### �����ź���:

��1�������ź��������ȼ��̳еĻ��ƣ�����ֻ�����������У������������жϷ������У�

��2���жϷ������в�������ΪҪ�ȴ������ź�������������̬��**������������������жϾ��Բ�����**��;



##### �����ʱ��

��1�������ʱ���Ļص������о��Բ�����ʹ����ʱ ���߻ᵼ�������ĺ�������ȴ���ӣ��ź����ȣ�



##### �¼���־��

�ź���ֻ��ͬ�������������¼���ĳ��������Ҫ������������¼�����ͬ��ʱ�����¼���־�飻



##### 2. ʹ���ⲿ�豸 DEVICE_EXPORT ( Linux �����л��������д��, FreeRTOS ����ģ�� Linux)

**DEVICE_EXPORT**

service �������ϲ�API �� �²� API�� �²�API�������ײ���ã��ϲ�API ��Ӧ�ò���ã��ǲ���Linux��serviceҲ������ʵ�ֵģ���������ǣ��Ͼ���ǰ�������ֻ��ģ�

https://zhuanlan.zhihu.com/p/356482765



```C
// dev_bt_spp.c ��
bt_spp_drv_io_t user_bt_spp_ops = 
{
  	// .init
  	.spp_send = user_spp_send,
 	.spp_recv = user_spp_recv,
	// .deinit
};
DEVICE_EXPORT(dev_bt_spp_link, &user_bt_spp_ops);
```

service ����:

device_bt_spp.h

```C
// �����ӿ�
typedef struct
{
  	bool (*spp_send)(BT_SPP_HANDLER_E handler, uint8_t channel, uint8_t *p_data, uint 16_t len);
  	// �������������ӿ�, init, deinit, send, recv, ���͵� Linux ����д��
}

// abstract device type
typedef struct
{
  	const char *name;	//device name
	const bt_spp_drv_io_t *ops;	// device IO of BT SPP
} bt_spp_drv_type_t;  // �����豸����
```

dev_bt_spp.c

```C
bt_spp_drv_type_t g_bt_spp_deviec;
// dev_bt_spp.c
void dev_bt_spp_link(const void *pdriver)
{
  	g_bt_spp_device.name = "Dev-bt-spp";
  	g_bt_spp_device.ops  = (bt_spp_drv_io_t*)pdriver;
}
```

�û��ӿڷ��棺��ֱ�ӵ��õײ�ӿڣ�ͨ����װ�õ� user_xx_yy �ӿ�

user_bt_spp.c

```C
// ���ͺ��������ϲ��û����õĽӿڣ�
void user_spp_send(BT_SPP_HANDLER_E handler, uint8_t channel, uint8_t *p_data, uint16_t len)
{
  	// ���ݲ�ͬ�� Hander, channel ��װ��ͬ��ͷ������ ���͵� bt_send_thread �Ķ����� 
}

bt_spp_drv_io_t user_bt_spp_ops = 
{
  	.spp_send = user_spp_send,
};
DEVICE_EXPORT(dev_bt_spp_link, &user_bt_spp_ops); // �ؼ�����
```

**DEVICE_EXPORT �ڲ������ʵ�ֵ�?**

spp_def.h

```C
// function define of abstract device
typedef void (*dev_ops_link)(const void *ops_ptr);

// �豸����
typedef struct _dev_desc
{
  	const char 			*func_name;
  	const void 			*ops_ptr;
  	const dev_ops_link	func;
} dev_desc_t;
#define _DEVICE_EXPORT(fn, ops_ptr, level) \
	const char _dev_init_##fn##_name[] = #fn; \ // ## �ַ���ƴ��, # ������ֵ����ַ���
	const dev_desc_t _dev_desc_##fn __attribute__((used, section(".device_init.$"level)))= \
							{_dev_init_##fn##_name, ops_ptr, &fn} // �������ĵط�

// (function name, operation_pointer)
#define DEVICE_EXPORT(fn, ops_ptr) _DEVICE_EXPORT(fn, ops_ptr, "f") // C ������ʹ�ÿɱ�����ķ�ʽ
```



##### 5.��ͬ��Э��֧�ֲ�ͬ��Ӧ�ó����������ͨ��һ���ײ���·��������·��֧�ֶ��ֲ�ͬ��Ӧ�ó������������ܶ�ѧϰ��

```C
void proto_data_recv(HANDLER_E handler, uint8_t channel, uint8_t *p_data, uint 32_t len);
```







##### 6. nuttx ����ϵͳѧϰ



