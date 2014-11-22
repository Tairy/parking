-- phpMyAdmin SQL Dump
-- version 4.2.11
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Nov 22, 2014 at 02:49 PM
-- Server version: 5.5.40-0ubuntu0.12.04.1
-- PHP Version: 5.3.10-1ubuntu3.15

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `parking`
--

-- --------------------------------------------------------

--
-- Table structure for table `car_pos`
--

CREATE TABLE IF NOT EXISTS `car_pos` (
`id` int(11) NOT NULL,
  `x` int(11) NOT NULL,
  `y` int(11) NOT NULL,
  `width` int(11) NOT NULL,
  `height` int(11) NOT NULL,
  `status` varchar(45) NOT NULL,
  `type` varchar(255) NOT NULL,
  `pos_num` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=39 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `car_pos`
--

INSERT INTO `car_pos` (`id`, `x`, `y`, `width`, `height`, `status`, `type`, `pos_num`) VALUES
(1, 0, 0, 64, 96, 'full', 'position', 1),
(2, 192, 0, 64, 96, 'free', 'position', 2),
(3, 128, 0, 64, 96, 'free', 'position', 3),
(4, 64, 0, 64, 96, 'free', 'position', 4),
(5, 256, 0, 64, 96, 'free', 'position', 5),
(6, 320, 0, 64, 96, 'free', 'position', 6),
(7, 384, 0, 64, 96, 'free', 'position', 7),
(8, 448, 0, 64, 96, 'free', 'position', 8),
(9, 576, 0, 64, 96, 'free', 'position', 9),
(10, 512, 0, 64, 96, 'free', 'position', 10),
(11, 256, 160, 64, 96, 'free', 'position', 11),
(12, 0, 160, 64, 96, 'free', 'position', 12),
(13, 64, 160, 64, 96, 'free', 'position', 13),
(14, 192, 160, 64, 96, 'free', 'position', 14),
(15, 128, 160, 64, 96, 'free', 'position', 15),
(16, 576, 160, 64, 96, 'free', 'position', 16),
(17, 512, 160, 64, 96, 'free', 'position', 17),
(18, 448, 160, 64, 96, 'free', 'position', 18),
(19, 384, 160, 64, 96, 'free', 'position', 19),
(20, 64, 320, 64, 96, 'free', 'position', 20),
(21, 0, 320, 64, 96, 'free', 'position', 21),
(22, 128, 320, 64, 96, 'free', 'position', 22),
(23, 192, 320, 64, 96, 'free', 'position', 23),
(24, 256, 320, 64, 96, 'free', 'position', 24),
(25, 64, 480, 64, 96, 'free', 'position', 25),
(26, 0, 480, 64, 96, 'free', 'position', 26),
(27, 128, 480, 64, 96, 'free', 'position', 27),
(28, 192, 480, 64, 96, 'free', 'position', 28),
(29, 256, 480, 64, 96, 'free', 'position', 29),
(30, 579, 320, 64, 96, 'free', 'position', 30),
(31, 387, 320, 64, 96, 'free', 'position', 31),
(32, 515, 320, 64, 96, 'free', 'position', 32),
(33, 451, 320, 64, 96, 'free', 'position', 33),
(34, 576, 480, 64, 96, 'free', 'position', 34),
(35, 448, 480, 64, 96, 'free', 'position', 35),
(36, 384, 480, 64, 96, 'free', 'position', 36),
(37, 512, 480, 64, 96, 'free', 'position', 37),
(38, 320, 608, 64, 32, 'free', 'door', 38);

-- --------------------------------------------------------

--
-- Table structure for table `config`
--

CREATE TABLE IF NOT EXISTS `config` (
`id` int(11) NOT NULL,
  `key` varchar(255) NOT NULL,
  `value` varchar(255) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=40 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `config`
--

INSERT INTO `config` (`id`, `key`, `value`) VALUES
(1, 'maploaded', 'true'),
(2, 'maploaded', 'true'),
(3, 'maploaded', 'true'),
(4, 'maploaded', 'true'),
(5, 'maploaded', 'true'),
(6, 'maploaded', 'true'),
(7, 'maploaded', 'true'),
(8, 'maploaded', 'true'),
(9, 'maploaded', 'true'),
(10, 'maploaded', 'true'),
(11, 'maploaded', 'true'),
(12, 'maploaded', 'true'),
(13, 'maploaded', 'true'),
(14, 'maploaded', 'true'),
(15, 'maploaded', 'true'),
(16, 'maploaded', 'true'),
(17, 'maploaded', 'true'),
(18, 'maploaded', 'true'),
(19, 'maploaded', 'true'),
(20, 'maploaded', 'true'),
(21, 'maploaded', 'true'),
(22, 'maploaded', 'true'),
(23, 'maploaded', 'true'),
(24, 'maploaded', 'true'),
(25, 'maploaded', 'true'),
(26, 'maploaded', 'true'),
(27, 'maploaded', 'true'),
(28, 'maploaded', 'true'),
(29, 'maploaded', 'true'),
(30, 'maploaded', 'true'),
(31, 'maploaded', 'true'),
(32, 'maploaded', 'true'),
(33, 'maploaded', 'true'),
(34, 'maploaded', 'true'),
(35, 'maploaded', 'true'),
(36, 'maploaded', 'true'),
(37, 'maploaded', 'true'),
(38, 'maploaded', 'true'),
(39, 'xmlpath', '/home/tairy/Documents/test.xml');

-- --------------------------------------------------------

--
-- Table structure for table `spaces`
--

CREATE TABLE IF NOT EXISTS `spaces` (
`id` int(11) NOT NULL,
  `car_num` varchar(255) CHARACTER SET utf8 NOT NULL,
  `place_id` int(11) NOT NULL,
  `in_time` datetime NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `spaces`
--

INSERT INTO `spaces` (`id`, `car_num`, `place_id`, `in_time`) VALUES
(1, '2', 1, '0000-00-00 00:00:00'),
(2, '111111', 2, '2014-11-11 19:34:42'),
(3, '111111', 2, '2014-11-11 19:39:32'),
(4, '111111', 1, '2014-11-11 19:53:12'),
(5, '请输入你的车牌号！', 0, '2014-11-11 20:00:01'),
(6, 'hahsh', 1, '2014-11-11 20:03:04'),
(7, 'test', 1, '2014-11-11 20:05:04'),
(11, 'sds', 1, '2014-11-11 20:08:57'),
(12, 'dd', 1, '2014-11-11 20:10:56'),
(13, '请输入你的车牌号！', 1, '2014-11-13 19:50:59'),
(14, 'dada', 2, '2014-11-13 21:04:34'),
(16, 'Assss', 1, '2014-11-21 14:41:09');

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE IF NOT EXISTS `user` (
`id` int(11) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`id`, `username`, `password`) VALUES
(1, 'admin', 'admin');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `car_pos`
--
ALTER TABLE `car_pos`
 ADD PRIMARY KEY (`id`);

--
-- Indexes for table `config`
--
ALTER TABLE `config`
 ADD PRIMARY KEY (`id`);

--
-- Indexes for table `spaces`
--
ALTER TABLE `spaces`
 ADD PRIMARY KEY (`id`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
 ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `car_pos`
--
ALTER TABLE `car_pos`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=39;
--
-- AUTO_INCREMENT for table `config`
--
ALTER TABLE `config`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=40;
--
-- AUTO_INCREMENT for table `spaces`
--
ALTER TABLE `spaces`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=19;
--
-- AUTO_INCREMENT for table `user`
--
ALTER TABLE `user`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=2;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
