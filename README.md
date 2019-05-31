# example_opencv ROS_package

## Descripción general
Tutorial básico del uso de OpenCV dentro de ROS comentado para que sea más complensible para los programadores que se están iniciando en ROS.

## Proceso de instalación
Se considera que la computadora del usuario ya tiene correctamente instalado ROS, GIT y que ya tiene la carpeta de `catkin_ws` correctamente inicializada.

Para asegurarse que se tiene correctamente instalado OpenCV, ejecutar la siguiente instruccións en una Terminal:
```
$ pkg-config –-modversion opencv
```
Debe responder con la versión de OpenCV. En caso que no tenga instalado OpenCV, ejecutar:
```
sudo apt-get install ros-kinetic-vision-opencv libopencv-dev python-opencv
```
En una Terminal ejecutar las siguientes instrucciones:
```
$ cd ~/catkin_ws/src
$ git clone https://github.com/aaceves/example_opencv.git
$ cd ~/catkin_ws
$ catkin build
$ source devel/setup.bash
```
El proceso de compilación debe terminar sin errores.

## Ejemplo de ejecución

En dos Terminales diferentes ejecutar cada una de las siguientes lineas:
```
$ roscore
$ rosrun example_opencv show_thisimage
```

## Autores y colaboradores
Este paquete fue preparado por el Dr. Alejandro Aceves-López para que sea más comprensible a los programadores nuevos de ROS.

## Referencias
[1] Haowei Zhang, “Configure OpenCV in ROS environment with cv_bridge”, publicado 15 nov 2016, (link)[https://www.youtube.com/watch?v=HqNJbx0uAv0]   
[2]  Patrick Mihelich, James Bowman, “Vision OpenCV Package”, (link)[http://wiki.ros.org/opencv]   
[3] Patrick Mihelich, “Image view Package”, consultado en enero 2018, (link)[http://wiki.ros.org/image_view]   
[4] Patrick Mihelich, James Bowma, “Converting between ROS images and OpenCV images in C++”, (link)[http://wiki.ros.org/cv_bridge/Tutorials]   
[5] Patrick Mihelich, “Image transport tutorials”, consultado en enero 2018, (link)[http://wiki.ros.org/image_transport/Tutorials/]   
[6] Patrick Mihelich, James Bowman, “Documentación cv_bridge”, (link) [http://docs.ros.org/jade/api/cv_bridge/html/c++/index.html]   
