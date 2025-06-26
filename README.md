Introduccion

Este informe presenta los avances y desarrollo de una estación de soldadura automatizada diseñada por estudiantes de ingeniería de distintas ramas (mecánica, electrónica, informática y automatización). El sistema integra componentes mecánicos, sensores, motores, controladores y una interfaz programada sobre Arduino. El objetivo es crear una estación capaz de ejecutar movimientos precisos que simulen una operación de soldadura de forma semiautónoma, con posibilidad de automatización completa en futuras iteraciones.

Integración Electrónica

La estación usa una placa Arduino UNO como unidad de control. Los componentes integrados incluyen:
Componente	Cantidad	Especificaciones
Sensor ultrasónico (HC-SR04)	1	Detección de distancia
Motor DC	1	Controlado por puente H
Botón de paro	1	Paro de emergencia
Placa Arduino	1	Controlador principal
Fuente de alimentación	1	12V DC, 30A
Pantalla LCD	1	Para leer resultados y datos
Sensor DHT22	1	Para analizar temperatura

Se realizó un diagrama de bloques y esquemático de conexión validado en Tinkercad® antes de las pruebas físicas.
El montaje inicia con la integración mecánica, ensamblando las piezas fabricadas en CNC (tornillo sin fin, carrito y soporte del motor) al chasis principal, asegurando su fijación con tornillos y soportes adecuados.
Luego se realiza la instalación electrónica, montando la placa Arduino, sensores (ultrasónico y DHT22), motor y pantalla LCD. El cableado se organiza con un arnés sencillo y se etiquetan los conectores para facilitar el mantenimiento.
Para la validación, se revisa continuidad eléctrica, se miden voltajes clave y se energiza el sistema sin carga. Se prueban los componentes uno a uno: primero sensores, luego motor con el control PID, y finalmente todo el sistema en conjunto.
Siguiendo el enfoque VDI 2206, se hace una integración gradual: se conecta cada módulo por separado, probando su funcionamiento antes de ensamblar el sistema completo, asegurando estabilidad y seguridad operativa.

Validaciones Múltiples (según VDI 2206)

Se aplicó la metodología VDI 2206 para realizar validaciones por dominio:
- Mecánico: verificado el movimiento lineal fluido tras ajustes.
- Electrónico: prueba de continuidad, respuesta de sensores y control de potencia.
- Control: validación del algoritmo en bucle, detección de posiciones y actuación del motor.
El sistema fue validado con soldaduras simuladas, obteniendo trayectorias coherentes. El controlador PID, por ahora manual, se planea automatizar en las siguientes fases.

Consideraciones Adicionales

Se prioriza la seguridad: el sistema cuenta con botón de paro y opera a bajo voltaje. Se enfatiza el uso educativo del proyecto para aprender conceptos de automatización y control embebido.
Desde el punto de vista de sostenibilidad, se usaron materiales reutilizables y el sistema fue diseñado para ser modular y replicable. La documentación (diagramas, código, planos) está siendo almacenada para posibles mejoras o adaptaciones futuras.

Conclusiones y Siguientes Pasos

La estación de soldadura automatizada ha logrado integraciones mecánicas y electrónicas funcionales. Las pruebas iniciales confirman la viabilidad del concepto. Se identificaron mejoras necesarias como la incorporación de sensores de temperatura, una interfaz LCD y la automatización del controlador PID.
En las semanas siguientes se espera:
- Finalizar la automatización del proceso.
- Integrar indicadores visuales.
- Realizar pruebas de estabilidad a largo plazo.
Este proyecto ejemplifica el trabajo colaborativo interdisciplinario y el enfoque de diseño mecatrónico aplicado a un entorno educativo.
