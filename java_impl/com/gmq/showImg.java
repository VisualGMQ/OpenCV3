package com.gmq;

import org.opencv.core.*;
import org.opencv.highgui.*;
import org.opencv.imgcodecs.Imgcodecs;
import org.opencv.imgproc.Imgproc;

import java.util.*;
import java.io.*;

public class showImg {
    public static void main(String[] args) {
        System.load(new File("./lib/libopencv_java410.dylib").getAbsolutePath());
        Mat img = Imgcodecs.imread("com/gmq/resource/image.jpg");
        Imgproc.resize(img, img, new Size(423, 600));
        HighGui.namedWindow("test", HighGui.WINDOW_AUTOSIZE);
        HighGui.imshow("test", img);
        HighGui.waitKey(0);
        HighGui.destroyWindow("test");
        System.exit(0);
    }
};