package com.gmq;

import java.io.*;
import org.opencv.core.*;
import org.opencv.highgui.*;
import org.opencv.imgcodecs.Imgcodecs;
import org.opencv.imgproc.Imgproc;

public class drawShape {
    public static void main(String[] args) {
        System.load(new File("./lib/libopencv_java410.dylib").getAbsolutePath());
        Mat img = Mat.zeros(new Size(500, 500), CvType.CV_8UC3);
        Imgproc.rectangle(img, new Point(100, 100), new Point(400, 400), new Scalar(0, 255, 0));
        Imgproc.line(img, new Point(100, 100), new Point(400, 400), new Scalar(0, 0, 255));
        Imgproc.line(img, new Point(400, 100), new Point(100, 400), new Scalar(0, 255, 255));
        for (int i = 0; i < 6; i++)
            Imgproc.ellipse(img, new Point(250, 250), new Size(100, 50), i * 30, 0, 360, new Scalar(255, 0, 0));
        Imgproc.circle(img, new Point(250, 250), 20, new Scalar(200, 200, 0), Imgproc.FILLED);
        Imgproc.putText(img, "this is drawShape", new Point(130, 80), 6, 1, new Scalar(255, 255, 255));
        HighGui.imshow("shapes", img);
        HighGui.waitKey();
        System.exit(0);
    }
}