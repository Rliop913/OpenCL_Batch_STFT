import librosa
import matplotlib.pyplot as plt
import numpy as np
# 프레임 크기 및 윈도우 함수 설정
frame_size = 2048
hop_size = 1024
window = 'hamming'


# 기존 STFT 프로그램 (librosa 사용)
def librosa_stft(x):
    stft = librosa.stft(x, n_fft=frame_size, hop_length=hop_size, window=window)
    return stft

ret = librosa_stft(librosa.tone(1000,sr=48000,length=4800))
temp =[]
for i in range(len(ret)):
    temp.append(np.abs(ret[i][0]))
print(temp)
plt.subplot(255)
plt.plot(np.abs(ret))
plt.title('Librosa STFT')
plt.show()