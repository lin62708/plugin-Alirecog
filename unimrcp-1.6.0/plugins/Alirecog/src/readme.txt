���ڰ��������ʶ��sdk2.0��д��mrcp server ������

����Centos6.9-64λ����ͨ�� �� win10 ���б���ͨ��

Ŀǰ����2·û���⣬��Ϊ�������ѷ���ֻ�ܲ���2·

����������� ��ο����²������

Linux��
�����û�а�װunimrcpserver ���Ȱ�װ��
�Ȱ�װunimrcp-deps-1.6.0����
cd unimrcp-deps-1.6.0
./build-dep-libs.sh

�Ȱ�װ1.6�汾��unimrcpserver���񣬽�ѹ�����Ƚ�ѹ���ϴ�
./bootstrap
./configure
make && make install

��װĬ�ϵ�·��
/usr/local/unimrcp
����һ�£��Ƿ��ܳɹ������������ɹ����˳���������

��Ŀ���غ󣬰� unimrcp-1.6.0\plugins �µ� Alirecog �ļ���
�ϴ������unimrcpsever���밲װ�����棬���ǽ�ѹunimrcpserver1.6ʱ�İ�װ����plugins�ļ�������

g++ -v �鿴g++�İ汾
gcc version 4.8.2 20121015 (Red Hat 4.8.2-5) (GCC) 
�������4.8.2��g++�汾���ȸ��������������޷�����ͨ��

��unimrcp-deps-1.6.0/libs �����
apr �� apr-util �����⽨��һ�������ӵ� unimrcp-master/libs

ע�⣺���°汾����������������������ʹ��
��Ҫ����freeswitch��unimrcpԴ��
��Ҫ����unimrcpserver��Դ��
������ʵʱ����ʶ�𣬹���ʵʱ����ʶ���ʹ����ȥ�ҵ�csdn�˽�


����������׼������
cd plugins/Alirecog
���� plugins/Alirecog/aliSdk2.0/NlsSdkCpp2.0/lib
rm -rf ɾ����linux ���ļ��У����㣬���鷳��ɾҲ���ԣ�
Ȼ���ٽ�ѹlinux ����ѹ��ɺ� ����src
plugins/Alirecog/src

make clean
make
���ɱ����һ�� Alireocg.so �Ķ�̬��
�ŵ� /usr/local/unimrcp/plugin
�Ѳ��ʹ�õ�unimrcpserver.xml �ŵ�/usr/local/unimrcp/conf ����

Ȼ������������

Window ���鷳��������д