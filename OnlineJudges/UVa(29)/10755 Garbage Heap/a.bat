@echo off
@color 0A
@echo WindowsϵͳVPN�ؼ�ϵͳ�������
@echo #######################################################
@echo #######   ���潫����VPN����ϵͳ���������   #######
@echo ####### ����������� ����ִ����ֱ�ӹرմ��� #######
@echo #######################################################
pause
sc config LanmanWorkstation start= AUTO
sc start LanmanWorkstation
sc config TapiSrv start= AUTO
sc start TapiSrv
sc config PolicyAgent start= AUTO
sc start PolicyAgent
sc config RasMan start= AUTO
sc start RasMan
sc config RemoteAccess start= AUTO
sc start RemoteAccess
@echo ������� ��������˳�
@echo #######################################################
pause
exit