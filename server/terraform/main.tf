provider "aws" {
  version = "~> 2.0"
  region  = "eu-west-1"
}

variable "user_data" {
  default = "cloud-config.yaml"
}

variable "thou-shalt-ip" {}

data "aws_ami" "amazon-linux-2" {
  most_recent = true
  owners      = ["amazon"]

  filter {
    name   = "name"
    values = ["amzn2-ami-hvm*"]
  }

}

resource "aws_default_vpc" "default" {
  tags = {
    Name = "Default VPC"
  }
}

resource "aws_security_group" "thou-shalt-security-group" {
  name        = "thou-shalt-security-group"
  vpc_id      = "${aws_default_vpc.default.id}"

  ingress {
    from_port   = 22
    to_port     = 22
    protocol    = "tcp"
    cidr_blocks = ["${var.thou-shalt-ip}/32"]
  }

  ingress {
    from_port   = 57121
    to_port     = 57121
    protocol    = "udp"
    cidr_blocks = ["${var.thou-shalt-ip}/32"]
  }

  ingress {
    from_port   = 8081
    to_port     = 8081
    protocol    = "tcp"
    cidr_blocks = ["0.0.0.0/0"]
  }

  egress {
    from_port   = 0
    to_port     = 0
    protocol    = "-1"
    cidr_blocks = ["0.0.0.0/0"]
  }
  tags = {
    name = "thou shalt"
  }
}

resource "aws_instance" "thou-shalt-instance" {
  key_name                    = "impossible-bodies"
  vpc_security_group_ids      = ["${aws_security_group.thou-shalt-security-group.id}"]
  instance_type               = "t2.nano"
  ami                         = "${data.aws_ami.amazon-linux-2.id}"
  user_data                   = "${file(var.user_data)}"
  associate_public_ip_address = true
  tags = {
    name = "thou shalt"
  }
}


output "thou-shalt-instance-ip" {
  value = "${aws_instance.thou-shalt-instance.public_ip}"
}
