#include "soprano.h"
#define PI 3.14159265358979

namespace Bytebeats
{
    static HWAVEOUT hWaveOut;

    VOID Abort(HANDLE hThreadBytebeat)
    {
        waveOutClose(hWaveOut);
        waveOutBreakLoop(hWaveOut);
        waveOutReset(hWaveOut);
        TerminateThread(hThreadBytebeat, 0);
        CloseHandle(hThreadBytebeat);
    }

    DWORD WINAPI Beat1(LPVOID lpvd)
    {
        while (1)
        {
            WAVEFORMATEX wfx =
            {
                WAVE_FORMAT_PCM, 1,
                8000, 8000,   // Hz
                1, 8, 0
            };
            waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

            BYTE sbuffer[17000 * 60];

            for (DWORD t = 0; t < sizeof(sbuffer); t++)
            {
                sbuffer[t] = (BYTE)(t >> 6 & 1 ? t >> 5 : t >> 2 * (t << 192));
            }

            WAVEHDR header = { (LPSTR)sbuffer, sizeof(sbuffer), 0, 0, 0, 0, 0, 0 };
            waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
            waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
            waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));

            Sleep(INFINITE);
        }
        return 0;
    }

    DWORD WINAPI Beat2(LPVOID lpvd)
    {
        while (1)
        {
            WAVEFORMATEX wfx =
            {
                WAVE_FORMAT_PCM, 1,
                10000, 10000,  // Hz
                1, 8, 0
            };
            waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

            BYTE sbuffer[17000 * 60];

            for (DWORD t = 0; t < sizeof(sbuffer); t++)
            {
                sbuffer[t] = (BYTE)((t & t / 3 & t / 5) * t / 4E3);
            }

            WAVEHDR header = { (LPSTR)sbuffer, sizeof(sbuffer), 0, 0, 0, 0, 0, 0 };
            waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
            waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
            waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));

            Sleep(INFINITE);
        }
        return 0;
    }

    DWORD WINAPI Beat3(LPVOID lpvd)
    {
        while (1)
        {
            WAVEFORMATEX wfx =
            {
                WAVE_FORMAT_PCM, 1,
                6000, 4400,  // Hz
                1, 8, 0
            };
            waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

            BYTE sbuffer[17000 * 60];

            for (DWORD t = 0; t < sizeof(sbuffer); t++)
            {
                sbuffer[t] = (BYTE)(89 + ((t / 2 * (t & 20384 ? 16 / 3 : t & 32768 ? 416 / 93 : 5) * (t & 65536 ? t & 4096 ? 3 / 2 : 1 : 1) & 127) + (t >> (t & 65536 ? 5 : 7) & 127) & 128));
            }

            WAVEHDR header = { (LPSTR)sbuffer, sizeof(sbuffer), 0, 0, 0, 0, 0, 0 };
            waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
            waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
            waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));

            Sleep(INFINITE);
        }
        return 0;
    }

    DWORD WINAPI BeatBasicPalygon(LPVOID lpvd)
    {

        while (1)
        {
            for (int i = 3222; i <= 10000; i++)
            {
                Beep(rand() % i, 22);
                Beep(rand() % i, 10);
                Beep(rand() % i + 3002, 44);
            }
        }

        return 0;
    }

    DWORD WINAPI Beat4(LPVOID lpvd)
    {
        while (1)
        {
            WAVEFORMATEX wfx =
            {
                WAVE_FORMAT_PCM, 1,
                6000, 4400,  // Hz
                1, 8, 0
            };
            waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

            BYTE sbuffer[17000 * 60];

            for (DWORD t = 0; t < sizeof(sbuffer); t++)
            {
                sbuffer[t] = (BYTE)((t + 1) * (t >> 6) | t * 1 ^ t << 43);
            }

            WAVEHDR header = { (LPSTR)sbuffer, sizeof(sbuffer), 0, 0, 0, 0, 0, 0 };
            waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
            waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
            waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));

            Sleep(INFINITE);
        }
        return 0;
    }

    DWORD WINAPI Beat5(LPVOID lpvd)
    {
        while (1)
        {
            WAVEFORMATEX wfx =
            {
                WAVE_FORMAT_PCM, 1,
                8000, 8000,  // Hz
                1, 8, 0
            };
            waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

            BYTE sbuffer[17000 * 60];

            for (DWORD t = 0; t < sizeof(sbuffer); t++)
            {
                sbuffer[t] = (BYTE)(t * (t & 3213 ? 3 : 2) * (5 - (3 & t >> (t & 4096 ? 2 : 1))) << (3 * t >> 5) | t >> 3);
            }

            WAVEHDR header = { (LPSTR)sbuffer, sizeof(sbuffer), 0, 0, 0, 0, 0, 0 };
            waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
            waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
            waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));

            Sleep(INFINITE);
        }
        return 0;
    }

    DWORD WINAPI Beat6(LPVOID lpvd)
    {
        while (1)
        {
            WAVEFORMATEX wfx =
            {
                WAVE_FORMAT_PCM, 1,
                8000, 8000,  // Hz
                1, 8, 0
            };
            waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

            BYTE sbuffer[17000 * 60];


            for (DWORD t = 0; t < sizeof(sbuffer); t++)
            {
                sbuffer[t] = PI + ((t >> 2) * cos(t | 200));
            }

            WAVEHDR header = { (LPSTR)sbuffer, sizeof(sbuffer), 0, 0, 0, 0, 0, 0 };
            waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
            waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
            waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));

            Sleep(INFINITE);
        }
        return 0;
    }
}
