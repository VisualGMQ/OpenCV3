package com.gmq;

import java.io.*;
import org.opencv.core.*;
import org.opencv.highgui.*;
import org.opencv.imgcodecs.Imgcodecs;
import org.opencv.imgproc.Imgproc;

public class blur {
    public static void main(String[] args) {
        System.load(new File("./lib/libopencv_java410.dylib").getAbsolutePath());
        Mat img = Imgcodecs.imread("com/gmq/resource/image.jpg");
        Imgproc.resize(img, img, new Size(423, 600));
        HighGui.imshow("image", img);
        HighGui.waitKey();
        // blur
        blur(img, 3);
        blur(img, 5);
        blur(img, 7);
        blur(img, 10);
        // GaussianBlur
        GaussianBlur(img, 3, 0);
        GaussianBlur(img, 3, 50);
        GaussianBlur(img, 5, 0);
        GaussianBlur(img, 5, 50);
        GaussianBlur(img, 7, 0);
        GaussianBlur(img, 7, 50);
        GaussianBlur(img, 9, 0);
        GaussianBlur(img, 9, 50);
        // medianBlur
        medianBlur(img, 3);
        medianBlur(img, 5);
        medianBlur(img, 7);
        medianBlur(img, 9);
        System.exit(0);
    }

    public static void blur(Mat img, int size) {
        Mat blurimg = new Mat();
        Imgproc.blur(img, blurimg, new Size(size, size));
        HighGui.imshow("blur(" + size + "x" + size + ")", blurimg);
        HighGui.waitKey();
    }

    public static void GaussianBlur(Mat img, int size, int sigmaX) {
        Mat blurimg = new Mat();
        Imgproc.GaussianBlur(img, blurimg, new Size(size, size), sigmaX);
        HighGui.imshow("GaussianBlur(" + size + "x" + size + ")" + "sigmaX:" + sigmaX, blurimg);
        HighGui.waitKey();
    }

    public static void medianBlur(Mat img, int size) {
        Mat blurimg = new Mat();
        Imgproc.medianBlur(img, blurimg, size);
        HighGui.imshow("medianBlur(" + size + "x" + size + ")", blurimg);
        HighGui.waitKey();
    }
}