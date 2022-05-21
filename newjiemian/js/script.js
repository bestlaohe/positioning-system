/*********************************************************************************************
* 初始化变量
*********************************************************************************************/
var myZCloudID = "736299660156";                                   // 智云帐号
var myZCloudKey = "BgMAVF0AUABTCFFXYFpYVlZORWg";                 // 智云密钥
var DemoMac = "totaldata";                    	// 节点MAC地址
var DemoMac1 = "minidata";                    	// 节点MAC地址
var rtc = new WSNRTConnect(myZCloudID, myZCloudKey);            // 创建数据连接服务对象
  
/*********************************************************************************************
* 与智云服务连接，并监听和解析实时数据并显示
*********************************************************************************************/  
$(function () 
{
  rtc.setServerAddr("api.zhiyun360.com:28080");                 // 设置服务器地址
  rtc.connect();                                                // 数据推送服务连接
  
  rtc.onConnect = function () {                                 // 连接成功回调函数
    rtc.sendMessage(DemoMac,"{正在运行消息回调函数}");
   // {"method":"sensor","addr":"gataway","data":"{h1=1,d1=22,a1=2,h2=1,d2=23,a2=2,	h3=1,d3=21,a3=2,h4=1,d4=15,a4=2,h5=1,d5=29,a5=2}"}
   /* rtc.sendMessage(DemoMac, "{h11=?,h12=?,h13=?,d11=??,d12=?,d13=???,a11=?,a12=?,a13=?,h21=?,h22=?,h23=?,d21=??,d22=??,d23=???,a21=?,a22=?,a23=?,h31=?,h32=?,h33=?,d31=??,d32=??,d33=?,a31=?,a32=?,a33=?,h41=?,h42=?,h43=?,d41=??,d42=??,d43=??,a41=?,a42=?,a43=?,h51=?,h52=?,h53=?,d51=??,d52=?,d53=??,a51=?,a52=?,a53=?}");               // 查询温湿度、灯光初始值
    rtc.sendMessage(DemoMac1, "{h11=?,h12=?,h13=?,d11=??,d12=?,d13=???,a11=?,a12=?,a13=?,h21=?,h22=?,h23=?,d21=??,d22=??,d23=???,a21=?,a22=?,a23=?,h31=?,h32=?,h33=?,d31=??,d32=??,d33=?,a31=?,a32=?,a33=?,h41=?,h42=?,h43=?,d41=??,d42=??,d43=??,a41=?,a42=?,a43=?,h51=?,h52=?,h53=?,d51=??,d52=?,d53=??,a51=?,a52=?,a53=?}");               // 查询温湿度、灯光初始值
   */ $("#ConnectState").text("数据服务连接成功！");
  };

  rtc.onConnectLost = function () {                             // 数据服务掉线回调函数
    $("#ConnectState").text("数据服务掉线！");
  };

  rtc.onmessageArrive = function (mac, dat) {                   // 消息处理回调函数
    console.log(mac+" >>> "+dat);
    if (mac == DemoMac) {                                   	// 判断是否是节点的数据

      if (dat[0] == '{' && dat[dat.length - 1] == '}') {        // 判断字符串首尾是否为{}
        dat = dat.substr(1, dat.length - 2);                    // 截取{}内的字符串
        var its = dat.split(',');                               // 以‘,’来分割字符串
        for (var x in its) {                                    // 循环遍历
          var t = its[x].split('=');                            // 以‘=’来分割字符串
          if (t.length != 2) continue;                          // 满足条件时结束当前循环

          if (t[0] == "d11") {                                   // 判断参数A0
            var hum = parseFloat(t[1]);                         // 读取温度数据
            $("#d11").text(hum + "米");                   // 在页面显示温度数据
          }
          if (t[0] == "d12") {                                   // 判断参数A1
            var hum = parseFloat(t[1]);                         // 读取湿度数据
            $("#d12").text(hum + "米");                   // 在页面显示湿度数据
          }
          if (t[0] == "d13") {                                   // 判断参数A0
            var hum = parseFloat(t[1]);                         // 读取温度数据
            $("#d13").text(hum + "米");                 // 在页面显示温度数据
          }
    
          if (t[0] == "d21") {                                   // 判断参数A1
            var hum = parseFloat(t[1]);                         // 读取湿度数据
            $("#d21").text(hum + "米");                   // 在页面显示湿度数据
          }
          if (t[0] == "d22") {                                   // 判断参数A1
            var hum = parseFloat(t[1]);                         // 读取湿度数据
            $("#d22").text(hum + "米");                   // 在页面显示湿度数据
          }
          if (t[0] == "d23") {                                   // 判断参数A1
            var hum = parseFloat(t[1]);                         // 读取湿度数据
            $("#d23").text(hum + "米");                   // 在页面显示湿度数据
          }


          if (t[0] == "d31") {                                   // 判断参数A1
            var hum = parseFloat(t[1]);                         // 读取湿度数据
            $("#d31").text(hum + "米");                   // 在页面显示湿度数据
          }
          if (t[0] == "d32") {                                   // 判断参数A1
            var hum = parseFloat(t[1]);                         // 读取湿度数据
            $("#d32").text(hum + "米");                   // 在页面显示湿度数据
          }
          if (t[0] == "d33") {                                   // 判断参数A1
            var hum = parseFloat(t[1]);                         // 读取湿度数据
            $("#d33").text(hum + "米");                   // 在页面显示湿度数据
          }

           if (t[0] == "d41") {                                   // 判断参数A1
            var hum = parseFloat(t[1]);                         // 读取湿度数据
            $("#d41").text(hum + "米");                   // 在页面显示湿度数据
          }
          if (t[0] == "d42") {                                   // 判断参数A1
            var hum = parseFloat(t[1]);                         // 读取湿度数据
            $("#d42").text(hum + "米");                   // 在页面显示湿度数据
          }
          if (t[0] == "d43") {                                   // 判断参数A1
            var hum = parseFloat(t[1]);                         // 读取湿度数据
            $("#d43").text(hum + "米");                   // 在页面显示湿度数据
          }


           if (t[0] == "d51") {                                   // 判断参数A1
            var hum = parseFloat(t[1]);                         // 读取湿度数据
            $("#d51").text(hum + "米");                   // 在页面显示湿度数据
          }
          if (t[0] == "d52") {                                   // 判断参数A1
            var hum = parseFloat(t[1]);                         // 读取湿度数据
            $("#d52").text(hum + "米");                   // 在页面显示湿度数据
          }
          if (t[0] == "d53") {                                   // 判断参数A1
            var hum = parseFloat(t[1]);                         // 读取湿度数据
            $("#d53").text(hum + "米");                   // 在页面显示湿度数据
          }





          if (t[0] == "a11") {                                   // 判断参数A0
                  var hum = parseFloat(t[1]);                         // 读取温度数据
                  if(t[1]==1)
                  $("#a1").text("危险");                 // 在页面显示温度数据
                  
          }
          if (t[0] == "a12") {                                   // 判断参数A0
                    var hum = parseFloat(t[1]);                         // 读取温度数据
                    if(t[1]==1)
                    $("#a2").text("危险");                 // 在页面显示温度数据
                  
                  }
          if (t[0] == "a13") {                                   // 判断参数A0
                    var hum = parseFloat(t[1]);                         // 读取温度数据
                    if(t[1]==1)
                    $("#a3").text("危险");                 // 在页面显示温度数据
                    
                  }
          if (t[0] == "a21") {                                   // 判断参数A0
                    var hum = parseFloat(t[1]);                         // 读取温度数据
                    if(t[1]==1)
                    $("#a1").text("危险");                 // 在页面显示温度数据
                    
                  }
          if (t[0] == "a22") {                                   // 判断参数A0
                    var hum = parseFloat(t[1]);                         // 读取温度数据
                    if(t[1]==1)
                    $("#a2").text("危险");                 // 在页面显示温度数据
                    
                  }
          if (t[0] == "a23") {                                   // 判断参数A0
                    var hum = parseFloat(t[1]);                         // 读取温度数据
                    if(t[1]==1)
                    $("#a3").text("危险");                 // 在页面显示温度数据
                    
                  }
          if (t[0] == "a31") {                                   // 判断参数A0
                    var hum = parseFloat(t[1]);                         // 读取温度数据
                    if(t[1]==1)
                    $("#a1").text("危险");                 // 在页面显示温度数据
                    
                  }
          if (t[0] == "a32") {                                   // 判断参数A0
                    var hum = parseFloat(t[1]);                         // 读取温度数据
                    if(t[1]==1)
                    $("#a2").text("危险");                 // 在页面显示温度数据
                    
                  }
          if (t[0] == "a33") {                                   // 判断参数A0
                    var hum = parseFloat(t[1]);                         // 读取温度数据
                    if(t[1]==1)
                    $("#a3").text("危险");                 // 在页面显示温度数据
                    
                  }
            if (t[0] == "a41") {                                   // 判断参数A0
                    var hum = parseFloat(t[1]);                         // 读取温度数据
                    if(t[1]==1)
                    $("#a1").text("危险");                 // 在页面显示温度数据
                   
                  }
          if (t[0] == "a42") {                                   // 判断参数A0
                    var hum = parseFloat(t[1]);                         // 读取温度数据
                    if(t[1]==1)
                    $("#a2").text("危险");                 // 在页面显示温度数据
                   
                  }
            if (t[0] == "a43") {                                   // 判断参数A0
                    var hum = parseFloat(t[1]);                         // 读取温度数据
                    if(t[1]==1)
                    $("#a3").text("危险");                 // 在页面显示温度数据
                   
                  }
          if (t[0] == "a51") {                                   // 判断参数A0
                    var hum = parseFloat(t[1]);                         // 读取温度数据
                    if(t[1]==1)
                    $("#a1").text("危险");                 // 在页面显示温度数据
                   
                  }

          if (t[0] == "a52") {                                   // 判断参数A0
                    var hum = parseFloat(t[1]);                         // 读取温度数据
                    if(t[1]==1)
                    $("#a2").text("危险");                 // 在页面显示温度数据
                    
                  }
            if (t[0] == "a53") {                                   // 判断参数A0
                    var hum = parseFloat(t[1]);                         // 读取温度数据
                    if(t[1]==1)
                    $("#a3").text("危险");                 // 在页面显示温度数据
                    
                  }


		
        }
      }
    }
 
   // {"method":"sensor","addr":"minidata","data":"{5,1,22,2,1,33,3,1,20}"}
   if (mac == DemoMac1){
    if (dat[0] == '{' && dat[dat.length - 1] == '}') {        // 判断字符串首尾是否为{}
      dat = dat.substr(1, dat.length - 2);                    // 截取{}内的字符
      var its = dat.split(',');                               // 以‘,’来分割字符串
     //单徽章的情况下
      if(its[1]==its[4])
      {
     
        if(its[1]==1)
        {
            var hum = parseFloat(its[2]);                         // 读取温度数据
            $("#md11").text(hum + "米");       
            var hum = parseFloat(its[5]);                         // 读取温度数据
            $("#md21").text(hum + "米");  
            var hum = parseFloat(its[8]);                         // 读取温度数据
            $("#md31").text(hum + "米");  
            var hum = parseFloat(its[0]);                         // 读取温度数据
            $("#w11").text( "位标"+hum ); 
            var hum = parseFloat(its[3]);                         // 读取温度数据
            $("#w21").text( "位标"+hum ); 
            var hum = parseFloat(its[6]);                         // 读取温度数据
            $("#w31").text( "位标"+hum );       
        }
        if(its[1]==2)
        {
          var hum = parseFloat(its[2]);                         // 读取温度数据
            $("#md12").text(hum + "米");       
            var hum = parseFloat(its[5]);                         // 读取温度数据
            $("#md22").text(hum + "米");  
            var hum = parseFloat(its[8]);                         // 读取温度数据
            $("#md32").text(hum + "米");  
            var hum = parseFloat(its[0]);                         // 读取温度数据
            $("#w12").text( "位标"+hum ); 
            var hum = parseFloat(its[3]);                         // 读取温度数据
            $("#w22").text( "位标"+hum ); 
            var hum = parseFloat(its[6]);                         // 读取温度数据
            $("#w32").text( "位标"+hum );       
        }
        if(its[1]==3)
        {
          var hum = parseFloat(its[2]);                         // 读取温度数据
            $("#md13").text(hum + "米");       
            var hum = parseFloat(its[5]);                         // 读取温度数据
            $("#md23").text(hum + "米");  
            var hum = parseFloat(its[8]);                         // 读取温度数据
            $("#md33").text(hum + "米");   
            var hum = parseFloat(its[0]);                         // 读取温度数据
            $("#w13").text( "位标"+hum ); 
            var hum = parseFloat(its[3]);                         // 读取温度数据
            $("#w23").text( "位标"+hum ); 
            var hum = parseFloat(its[6]);                         // 读取温度数据
            $("#w33").text( "位标"+hum );      
        }

      }
       // 2徽章情况下{"method":"sensor","addr":"minidata","data":"{5,1,22,5,2,22,2,1,33,2,2,33,3,1,20,3,2,20}"}
      if(its[1]==its[13])
      {
   

        var hum = parseFloat(its[3]);                         // 读取温度数据
        $("#w12").text( "位标"+hum ); 
        var hum = parseFloat(its[9]);                         // 读取温度数据
        $("#w22").text( "位标"+hum ); 
        var hum = parseFloat(its[15]);                         // 读取温度数据
        $("#w32").text( "位标"+hum ); 
        if(its[1]==1)
        {
            var hum = parseFloat(its[2]);                         // 读取温度数据
            $("#md11").text(hum + "米");       
            var hum = parseFloat(its[8]);                         // 读取温度数据
            $("#md21").text(hum + "米");  
            var hum = parseFloat(its[14]);                         // 读取温度数据
            $("#md31").text(hum + "米");  
            var hum = parseFloat(its[0]);                         // 读取温度数据
            $("#w11").text( "位标"+hum ); 
            var hum = parseFloat(its[6]);                         // 读取温度数据
            $("#w21").text( "位标"+hum ); 
            var hum = parseFloat(its[12]);                         // 读取温度数据
            $("#w31").text( "位标"+hum );       
        }
        if(its[1]==2)
        {
          var hum = parseFloat(its[2]);                         // 读取温度数据
            $("#md12").text(hum + "米");       
            var hum = parseFloat(its[8]);                         // 读取温度数据
            $("#md22").text(hum + "米");  
            var hum = parseFloat(its[14]);                         // 读取温度数据
            $("#md32").text(hum + "米");   
            var hum = parseFloat(its[0]);                         // 读取温度数据
            $("#w12").text( "位标"+hum ); 
            var hum = parseFloat(its[6]);                         // 读取温度数据
            $("#w22").text( "位标"+hum ); 
            var hum = parseFloat(its[12]);                         // 读取温度数据
            $("#w32").text( "位标"+hum );      
        }     
           if(its[1]==3)
        {
          var hum = parseFloat(its[2]);                         // 读取温度数据
            $("#md13").text(hum + "米");       
            var hum = parseFloat(its[8]);                         // 读取温度数据
            $("#md23").text(hum + "米");  
            var hum = parseFloat(its[14]);                         // 读取温度数据
            $("#md33").text(hum + "米"); 
            var hum = parseFloat(its[0]);                         // 读取温度数据
            $("#w13").text( "位标"+hum ); 
            var hum = parseFloat(its[6]);                         // 读取温度数据
            $("#w23").text( "位标"+hum ); 
            var hum = parseFloat(its[12]);                         // 读取温度数据
            $("#w33").text( "位标"+hum );        
        }
        if(its[4]==1)
        {
          var hum = parseFloat(its[5]);                         // 读取温度数据
            $("#md11").text(hum + "米");       
            var hum = parseFloat(its[11]);                         // 读取温度数据
            $("#md21").text(hum + "米");  
            var hum = parseFloat(its[17]);                         // 读取温度数据
            $("#md31").text(hum + "米"); 
            var hum = parseFloat(its[3]);                         // 读取温度数据
            $("#w11").text( "位标"+hum ); 
            var hum = parseFloat(its[9]);                         // 读取温度数据
            $("#w21").text( "位标"+hum ); 
            var hum = parseFloat(its[15]);                         // 读取温度数据
            $("#w31").text( "位标"+hum );        
        }

        if(its[4]==2)
        {
          var hum = parseFloat(its[5]);                         // 读取温度数据
            $("#md12").text(hum + "米");       
            var hum = parseFloat(its[11]);                         // 读取温度数据
            $("#md22").text(hum + "米");  
            var hum = parseFloat(its[17]);                         // 读取温度数据
            $("#md32").text(hum + "米");  
            var hum = parseFloat(its[3]);                         // 读取温度数据
            $("#w12").text( "位标"+hum ); 
            var hum = parseFloat(its[9]);                         // 读取温度数据
            $("#w22").text( "位标"+hum ); 
            var hum = parseFloat(its[15]);                         // 读取温度数据
            $("#w32").text( "位标"+hum );       
        }  
        if(its[4]==3)
        {
          var hum = parseFloat(its[5]);                         // 读取温度数据
            $("#md13").text(hum + "米");       
            var hum = parseFloat(its[11]);                         // 读取温度数据
            $("#md23").text(hum + "米");  
            var hum = parseFloat(its[17]);                         // 读取温度数据
            $("#md33").text(hum + "米"); 
            var hum = parseFloat(its[3]);                         // 读取温度数据
            $("#w13").text( "位标"+hum ); 
            var hum = parseFloat(its[9]);                         // 读取温度数据
            $("#w23").text( "位标"+hum ); 
            var hum = parseFloat(its[15]);                         // 读取温度数据
            $("#w33").text( "位标"+hum );        
        }

      }
     // 3徽章情况下{"method":"sensor","addr":"minidata","data":"{5,1,22,5,2,22,5,3,21,2,1,37,2,2,39,2,3,33,3,1,20,3,2,20,3,3,28}"}  
          if(its[1]==1&&its[4]==2&&its[7]==3)
       {
        var hum = parseFloat(its[0]);                         // 读取温度数据
        $("#w11").text( "位标"+hum ); 
        var hum = parseFloat(its[9]);                         // 读取温度数据
        $("#w21").text( "位标"+hum ); 
        var hum = parseFloat(its[18]);                         // 读取温度数据
        $("#w31").text( "位标"+hum ); 

        var hum = parseFloat(its[3]);                         // 读取温度数据
        $("#w12").text( "位标"+hum ); 
        var hum = parseFloat(its[12]);                         // 读取温度数据
        $("#w22").text( "位标"+hum ); 
        var hum = parseFloat(its[21]);                         // 读取温度数据
        $("#w32").text( "位标"+hum ); 

        var hum = parseFloat(its[6]);                         // 读取温度数据
        $("#w13").text( "位标"+hum ); 
        var hum = parseFloat(its[15]);                         // 读取温度数据
        $("#w23").text( "位标"+hum ); 
        var hum = parseFloat(its[24]);                         // 读取温度数据
        $("#w33").text( "位标"+hum ); 
      
           var hum = parseFloat(its[2]);                         // 读取温度数据
             $("#md11").text(hum + "米");       
             var hum = parseFloat(its[11]);                         // 读取温度数据
             $("#md21").text(hum + "米");  
             var hum = parseFloat(its[20]);                         // 读取温度数据
             $("#md31").text(hum + "米");        
      
           var hum = parseFloat(its[5]);                         // 读取温度数据
             $("#md12").text(hum + "米");       
             var hum = parseFloat(its[14]);                         // 读取温度数据
             $("#md22").text(hum + "米");  
             var hum = parseFloat(its[23]);                         // 读取温度数据
             $("#md32").text(hum + "米");        
      
           var hum = parseFloat(its[8]);                         // 读取温度数据
             $("#md13").text(hum + "米");       
             var hum = parseFloat(its[17]);                         // 读取温度数据
             $("#md23").text(hum + "米");  
             var hum = parseFloat(its[26]);                         // 读取温度数据
             $("#md33").text(hum + "米");        
       
 
       }

    }
  }
  };

});
    
/*
{"method":"sensor","addr":"gataway","data":"{beacon_Num 1 2 3，distance:[22, 22, 22, 22, 22,22, 22, 33， 33]index_Num":[1, 2, 3,3,4, 5, 6, 7,8]}"}
{A1=?,A2=?,D1=?}
{"method":"sensor","addr":"gataway","data":" {A1=1,A2=2,A3=3,d1=23,d2=24,d3=21,d5=20,d6=11,d7=12,d8=10,d9=1}"}
{"method":"sensor","addr":"gataway","data":"{h1=1,d1=22,a1=2,h2=1,d2=23,a2=2,	h3=1,d3=21,a3=2,	h4=1,d4=15,a4=2,	h5=1,d5=29,a5=2,}"}

{"method":"sensor","addr":"gataway","data":"{h1=1,d1=22,a1=2,h2=1,d2=23,a2=2,	h3=1,d3=21,a3=2,h4=1,d4=15,a4=2,h5=1,d5=29,a5=2}"}

表示徽章1，距离22，无报警全数据包括报警
{"method":"sensor","addr":"gataway","data":"{h11=1,h12=1,h13=1,d11=22,d12=2,d13=222,a11=2,a12=2,a13=2,   h2=1,d2=23,a2=2,	h3=1,d3=21,a3=2,h4=1,d4=15,a4=2,h5=1,d5=29,a5=2}"}

{"method":"sensor","addr":"gataway","data":"{h11=1,h12=1,h13=1,d11=22,d12=2,d13=222,a11=2,a12=2,a13=2,h21=1,h22=2,h23=3,d21=23,d22=24,d23=244,a21=2,a22=2,a23=2,h31=1,h32=2,h33=3,d31=21,d32=24,d33=5,a31=2,a32=1,a33=1,h41=1,h42=2,h43=3,d41=15,d42=25,d43=35,a41=2,a42=2,a43=2,h51=1,h52=2,h53=3,d51=29,d52=3,d53=40,a51=2,a52=2,a53=1}"}

*/