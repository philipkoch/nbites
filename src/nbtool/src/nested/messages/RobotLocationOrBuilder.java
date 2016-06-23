// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: RobotLocation.proto

package messages;

public interface RobotLocationOrBuilder
    extends com.google.protobuf.MessageOrBuilder {

  // optional float x = 1;
  /**
   * <code>optional float x = 1;</code>
   */
  boolean hasX();
  /**
   * <code>optional float x = 1;</code>
   */
  float getX();

  // optional float y = 2;
  /**
   * <code>optional float y = 2;</code>
   */
  boolean hasY();
  /**
   * <code>optional float y = 2;</code>
   */
  float getY();

  // optional float h = 3;
  /**
   * <code>optional float h = 3;</code>
   */
  boolean hasH();
  /**
   * <code>optional float h = 3;</code>
   */
  float getH();

  // optional int64 timestamp = 4;
  /**
   * <code>optional int64 timestamp = 4;</code>
   */
  boolean hasTimestamp();
  /**
   * <code>optional int64 timestamp = 4;</code>
   */
  long getTimestamp();

  // optional float uncert = 5;
  /**
   * <code>optional float uncert = 5;</code>
   */
  boolean hasUncert();
  /**
   * <code>optional float uncert = 5;</code>
   */
  float getUncert();

  // optional bool lost = 6;
  /**
   * <code>optional bool lost = 6;</code>
   */
  boolean hasLost();
  /**
   * <code>optional bool lost = 6;</code>
   */
  boolean getLost();
}
