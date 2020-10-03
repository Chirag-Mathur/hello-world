import matplotlib.pyplot as plt
ele = ['2K','4K','6K','8K','10K']
# y1 = [8.8,8.9,9.3,10.6,10.6]
# y2 = [3.4,3.6,3.9,4,4.4]
# y3 = [981.2,2695.8,3429.1,3644.8,3828.7]
# y1 = [0.6,	1.6,	1.9,	2,	2.2]
# y2 = [3.4,	3.7,	4,	4.2,	4.3]
# y3 = [1042.8,	1741.6,	2516.5,	4370.2,	4894.7]
y1 = [132.2,	397.0,	473.0,	829.5,	1099.2]
y2 = [180.5,	384.4,	668.3,	928.0,	1146.5]
y3 = [2549.8,	3545.9,	4772.3,	5744.7,	6721.3]
plt.plot(ele,y1,label="A[]")
plt.plot(ele,y2,label="B[]")
plt.plot(ele,y3,label="C[]")
plt.xlabel('Number of Elements')
plt.ylabel('Time Taken')
plt.title('Time Analysis for deletion')
plt.legend()
plt.show()