@echo off
@color 0A
@echo Windows系统VPN关键系统服务项开启
@echo #######################################################
@echo #######   下面将开启VPN所需系统服务项操作   #######
@echo ####### 按任意键继续 不想执行请直接关闭窗口 #######
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
@echo 操作完成 按任意键退出
@echo #######################################################
pause
exit