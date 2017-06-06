/**
 * Created by rdimri on 10/17/16.
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.text.SimpleDateFormat;
import java.util.Date;

class UDPClient {
    static final String splunkIpAddr = "10.1.42.3";
    static final int destPort = 5142;
    public static void main(String args[]) throws Exception {
        System.out.println("Start UDPCLient");
      //  BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
       // BufferedReader durationFromUser = new BufferedReader(new InputStreamReader(System.in));
        InetAddress IPAddress = InetAddress.getByName(splunkIpAddr);
        byte[] sendData = new byte[1024];
      //  byte[] receiveData = new byte[1024];
        String sentence = null;
        //System.out.println("Test time in Secondes?");
       // String timeStr = durationFromUser.readLine();
        long durationInMs = 120000L;
//        if (timeStr != null && !timeStr.isEmpty())
//            durationInMs = 1000L * Long.parseLong(timeStr);
        long starttime = System.currentTimeMillis();
        long duration = starttime + durationInMs;
        SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.S");
        String startTimeStr = df.format(new Date(starttime));

        System.out.println("Starttime: " + startTimeStr + " Duration: " + durationInMs);
        DatagramSocket clientSocket = new DatagramSocket();
        int i = 0;
        boolean stoptimeOK = false;
        long controltime = 0L;
        int byteSize = 0;
        while (!stoptimeOK) {
            sentence = "UDP_Msg_";
            sentence = sentence.concat("" + df.format(new Date(System.currentTimeMillis())) + " ");
            sendData = sentence.getBytes();
            byteSize = byteSize + sendData.length;
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, destPort);
            clientSocket.send(sendPacket);
            Thread.sleep(100);
            controltime = System.currentTimeMillis();
            if (controltime >= duration) {
                stoptimeOK = true;
            }
        }
        clientSocket.close();
        String finishTime = df.format(new Date(controltime));
        System.out.println("EndeTime:  " + finishTime + " ByteSize " + byteSize);
        System.out.println("Finish");
    }
}

