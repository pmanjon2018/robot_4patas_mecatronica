import pybullet as p
import pybullet_data
import time
import math

physicsClient = p.connect(p.GUI)
p.setAdditionalSearchPath(pybullet_data.getDataPath())
p.setGravity(0, 0, -9.81)

sueloId = p.loadURDF("plane.urdf")
robotStartPos = [0, 0, 0.10]
robotStartOrientation = p.getQuaternionFromEuler([0, 0, 0])
robotId = p.loadURDF("cuadrupedo.urdf", robotStartPos, robotStartOrientation)

num_joints = p.getNumJoints(robotId)
print(f"\n--- ROBOT CUADRÚPEDO DETECTADO ---")
print(f"Número de servomotores activos en simulación: {num_joints}")

FUERZA_MAX_MOTOR = 0.215
angulo_muslo = 0.52
angulo_tibia = -0.78


for i in range(p.getNumJoints(robotId)):
    name = p.getJointInfo(robotId, i)[1].decode("utf-8")

    if "thigh" in name:
        target = 0.15
    else:
        target = 1.85

    p.setJointMotorControl2(
        robotId, i,
        p.POSITION_CONTROL,
        targetPosition=target,
        force=0.215
    )

print("\nRobot en posición fija. Presiona Ctrl+C para salir.")
try:
    while True:
        p.stepSimulation()
        time.sleep(1./240.)
except KeyboardInterrupt:
    p.disconnect()
    print("\nSimulación finalizada correctamente.")