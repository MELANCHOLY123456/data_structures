import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# 3D 画布
fig = plt.figure(figsize=(7,7))
ax = fig.add_subplot(111, projection='3d')

# 8 个面的顶点
vertices = np.array([
    [1,0,0], [-1,0,0],
    [0,1,0], [0,-1,0],
    [0,0,1], [0,0,-1]
])

# 8 个三角形面
faces = [
    [0,2,4], [0,3,4], [1,2,4], [1,3,4],
    [0,2,5], [0,3,5], [1,2,5], [1,3,5]
]

# 画出来
for f in faces:
    v = vertices[f]
    ax.plot_trisurf(v[:,0], v[:,1], v[:,2],
                    color='lightblue', alpha=0.7, linewidth=1)

ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_zlabel("z")
ax.set_title("|x| + |y| + |z| = 1")
plt.show()