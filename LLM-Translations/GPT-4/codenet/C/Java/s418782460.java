import java.util.*;

public class s418782460 {
    private static final int MAX_STRING = 30;
    private static final int MAX_LINE = 2000000;
    private static final int MAX_HUMAN = 200000;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String sInput;
        String[] psInput;

        int nHumanNumber;
        int nNextHumanIndex = 0;
        int nWaterLength;
        int nWaterLife = 0;
        int nStart;
        int nStop;

        // read line 1
        sInput = scanner.nextLine().trim();
        psInput = sInput.split(" ");
        nHumanNumber = Integer.parseInt(psInput[0]);
        nWaterLength = Integer.parseInt(psInput[1]);
        int[] anComingSec = new int[nHumanNumber];

        sInput = scanner.nextLine().trim();
        psInput = sInput.split(" ");
        for (int i = 0; i < nHumanNumber; i++) {
            anComingSec[i] = Integer.parseInt(psInput[i]);
        }

        nStart = anComingSec[0];

        while (nNextHumanIndex < nHumanNumber) {
            if (nNextHumanIndex == nHumanNumber) {
                break;
            } else {
                nStop = nStart + nWaterLength;
                if (anComingSec[nNextHumanIndex] < nStop) {
                    while (nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop) {
                        if (nStop <= anComingSec[nNextHumanIndex] + nWaterLength) {
                            nStop = anComingSec[nNextHumanIndex] + nWaterLength;
                            nNextHumanIndex++;
                        }
                    }
                    if (nNextHumanIndex == nHumanNumber) {
                        nWaterLife = nWaterLife + (nStop - nStart);
                        break;
                    }
                }
                nWaterLife = nWaterLife + (nStop - nStart);
                nStart = nStop;
                if (nStart < anComingSec[nNextHumanIndex]) {
                    nStart = anComingSec[nNextHumanIndex];
                }
            }
        }
        System.out.println(nWaterLife);
    }
}
// 
